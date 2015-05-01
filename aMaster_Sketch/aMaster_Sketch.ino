  #include <ADC.h>  // Teensy 3.0/3.1 uncomment this line and install http://github.com/pedvide/ADC
  #include <MozziGuts.h>
  #include <Oscil.h>
  
  #include <Sample.h> // Sample template
  #include <samples/burroughs1_18649_int8.h> // a converted audio sample included in the Mozzi download
  
  #include <ADSR.h>
  #include <mozzi_midi.h>
  #include <EventDelay.h>
  #include <mozzi_midi.h>
  #include <LiquidCrystalFast.h>
  #include <Encoder.h>
  
  // Bamboo Samples ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
  #include <samples/bamboo/bamboo_00_2048_int8.h> // wavetable data
  #include <samples/bamboo/bamboo_01_2048_int8.h> // wavetable data
  #include <samples/bamboo/bamboo_02_2048_int8.h> // wavetable data
  #include <samples/bamboo/bamboo_03_2048_int8.h> // wavetable data
  #include <samples/bamboo/bamboo_04_2048_int8.h> // wavetable data
  #include <samples/bamboo/bamboo_05_2048_int8.h> // wavetable data
  #include <samples/bamboo/bamboo_06_2048_int8.h> // wavetable data
  #include <samples/bamboo/bamboo_07_2048_int8.h> // wavetable data
  #include <samples/bamboo/bamboo_08_2048_int8.h> // wavetable data
  #include <samples/bamboo/bamboo_09_2048_int8.h> // wavetable data
  #include <samples/bamboo/bamboo_10_2048_int8.h> // wavetable data
  
  
  const int8_t * tables[16] ={
    BAMBOO_00_2048_DATA,
    BAMBOO_01_2048_DATA,
    BAMBOO_02_2048_DATA,
    BAMBOO_03_2048_DATA,
    BAMBOO_04_2048_DATA,
    BAMBOO_05_2048_DATA,
    BAMBOO_06_2048_DATA,
    BAMBOO_07_2048_DATA,
    BAMBOO_08_2048_DATA,
    BAMBOO_09_2048_DATA,
    BAMBOO_10_2048_DATA,
  };
  
  // use: Sample <table_size, update_rate> SampleName (wavetable)
  float recorded_pitch = (float) BURROUGHS1_18649_SAMPLERATE / (float) BURROUGHS1_18649_NUM_CELLS;
  Sample <BURROUGHS1_18649_NUM_CELLS, AUDIO_RATE> aSample(BAMBOO_00_2048_DATA); 
  
  // Encoder setup ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Encoder knob1(2, 3);
  Encoder knob2(5, 6);
  Encoder knob3(8, 9);
  Encoder knob4(11, 12);
  
  long position1  = -999;
  long position2  = -999;
  long position3  = -999;
  long position4  = -999;
  
  // Configure knobs ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //what is the difference between these two ways of declaring variables?
  const int NUMKNOBS = 4;
  #define NUM_VOICES 3
  
  int pitches[NUMKNOBS] = {
    57, 61, 64, 66};
  
  int knobpin[NUMKNOBS] = {
    1, 4, 7, 10};
  
  
  // Trellis stuff ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  #include <i2c_t3.h>
  #include "Adafruit_Trellis.h"
  
  Adafruit_Trellis matrix = Adafruit_Trellis();
  Adafruit_TrellisSet trellis = Adafruit_TrellisSet(&matrix);
  
  #define NUMTRELLIS 1
  #define numKeys (NUMTRELLIS * 16)
  
  #define INTPIN 31
  
  // Delays    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  EventDelay del;
  EventDelay lightDel;
  
  // initialize the library with the numbers of the interface pins
  LiquidCrystalFast lcd(14, 15, 16, 20, 21, 22, 23);
  // LCD pins: RS  RW  EN  D4  D5  D6  D7
  
  boolean current[NUMKNOBS];
  boolean previous[NUMKNOBS];
  int storage[NUMKNOBS];
  
  // ADSR Stuff     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  ADSR <CONTROL_RATE, AUDIO_RATE> envelope0;
  ADSR <CONTROL_RATE, AUDIO_RATE> envelope1;
  ADSR <CONTROL_RATE, AUDIO_RATE> envelope2;
  ADSR <CONTROL_RATE, AUDIO_RATE> envelope[NUM_VOICES] = {
    envelope0, envelope1, envelope2};
  
  #include <tables/sin8192_int8.h> // a converted audio sample included in the Mozzi download
  
  // use: Sample <table_size, update_rate> SampleName (wavetable)
  Oscil <8192, AUDIO_RATE> aOscil0(SIN8192_DATA);
  Oscil <8192, AUDIO_RATE> aOscil1(SIN8192_DATA);
  Oscil <8192, AUDIO_RATE> aOscil2(SIN8192_DATA);
  Oscil <8192, AUDIO_RATE> oscilator[NUM_VOICES] = {
    aOscil0, aOscil1, aOscil2};
  
  //  float recorded_pitch = (float) BAMBOO_00_2048_SAMPLERATE / (float) BAMBOO_00_2048_NUM_CELLS ;
  //  Sample <BAMBOO_00_2048_NUM_CELLS, AUDIO_RATE> aSample(BAMBOO_00_2048_DATA); 
  
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
  void setup(){
    // Configure knobs
    for (uint8_t i = 0; i < NUMKNOBS; i++) {
      pinMode(knobpin[i], INPUT_PULLUP);
    }
    // Configure LCD
    lcd.begin(16, 2);
  
    // Set EventDelays
    del.set(50);
    lightDel.set(500);
  
  
    for(uint8_t i=0; i<NUM_VOICES; i++){
      envelope[i].noteOff();
  
      //  Set envelope params  
      byte attack_level = 250;
      byte decay_level = 150;
      envelope[i].setADLevels(attack_level,decay_level);
  
      unsigned int attack, decay, sustain, release_ms;
      attack = 10;
      decay = 100;
      sustain = 6000;
      release_ms = 50;  
  
      envelope[i].setTimes(attack,decay,sustain,release_ms);   
    }
  
    // Initialize trellis
    pinMode(INTPIN, INPUT);
    digitalWrite(INTPIN, HIGH);
    trellis.begin(0x70); // Trellis address
  
    //Clear LEDs
    for (uint8_t i=0; i < numKeys; i++) {
      trellis.clrLED(i); 
    }
    trellis.writeDisplay();
  
    Serial.begin(9600); // for Teensy 3.0/3.1, beware printout can cause glitches
    //  Serial.begin(115200); // set up the Serial output so we can look at the piezo values // set up the Serial output so we can look at the piezo values
    startMozzi(); // :))
  }
  
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
  void playNote(uint8_t note, uint8_t voice) {
  
    if (voice == NUM_VOICES) {
      oscilator[0].setFreq((mtof(pitches[note])));
      envelope[0].noteOn();
  
      //find O in storage[];
      for(uint8_t repl=0; repl < NUMKNOBS; repl++) {
        if(storage[repl] == 0) {
          // Rbeplace it with -1
          storage[repl] = -1;
        }
      }
      storage[note] = 0;
    }
    // If the envelope is free, assign pitch to oscilator and play note
    else  if(!envelope[voice].playing()) {
      oscilator[voice].setFreq((mtof(pitches[note])));
      envelope[voice].noteOn();
      //Store note value
      storage[note] = voice;
    }  
    else if(envelope[voice].playing()){
      playNote(note, voice+1);
    }
  
  }
  
  void stopNote(int note){
    envelope[storage[note]].noteOff();
  }
  
  void buttonMessages(){
  
    for (uint8_t i = 0; i < NUMKNOBS; i++) {
  
      //if knob button pressed
      if (digitalRead(knobpin[i]) == 0){
        //pin index current is true
        current[i] = true; 
      }
      else if (digitalRead(knobpin[i]) == 1){
        //pin index current is false
        current[i] = false;  
      } 
  
      //if recent change; current = !previous
      if(current[i] == !previous[i]){
        //if recently pressed
        if(current[i]) {
          playNote(i, 0);
        }
        else if (!current[i]) {
          stopNote(i);
        }
      }
      previous[i] = current[i];
    }
  }
  
  void setEnvelopeParams (long new1, long new2, long new3, long new4) {
    byte ratio =  map(new3, 50, -50, 1, 5);
  
    uint8_t val =  255/(ratio+1);
    //uint8_t val = 255;
  
  
    byte attack_level = val*ratio;
    byte decay_level = val;
    envelope[0].setADLevels(attack_level,decay_level);
    envelope[1].setADLevels(attack_level,decay_level);
    envelope[2].setADLevels(attack_level,decay_level);
  
    unsigned int attack, decay, sustain, release_ms;
    attack = map(new1, 100, -100, 50, 999);
    decay =  map(new2, 100, -100, 50, 999);
    sustain = 6000;
    release_ms =  map(new4, -100, 100, 100, 999);  
  
    envelope[0].setTimes(attack,decay,sustain,release_ms); 
    envelope[1].setTimes(attack,decay,sustain,release_ms);
    envelope[2].setTimes(attack,decay,sustain,release_ms);  
  
  
    //Update Display
    lcd.setCursor(0, 0);
    lcd.print("Atk");
    if(attack<100){
  
      lcd.setCursor(0, 1);
      lcd.print(" ");
      lcd.setCursor(1, 1);      
      lcd.print(attack);
    }
    else{
      lcd.setCursor(0, 1);
      lcd.print(attack);
    }
  
    lcd.setCursor(4, 0);
    lcd.print("Dcy");
    if(decay<100){
      lcd.setCursor(4, 1);
      lcd.print(" ");
      lcd.setCursor(5, 1);      
      lcd.print(decay);
    }
    else{
      lcd.setCursor(4, 1);
      lcd.print(decay);
    }
  
    lcd.setCursor(8, 0);
    lcd.print("Rat");
    lcd.setCursor(8, 1);
    lcd.print(ratio);
    lcd.setCursor(9, 1);
    lcd.print(":1");
  
    lcd.setCursor(12, 0);
    lcd.print("Rel");
    lcd.setCursor(12, 1);
    lcd.print(release_ms);
  
    //Update Positions
    position1 = new1;
    position2 = new2;
    position3 = new3;
    position4 = new4;
  }
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
  
  void updateControl(){
    // To hold knob values
    long new1, new2, new3, new4;
    new1 = constrain(knob1.read(), -100, 100);
    new2 = constrain(knob2.read(), -100, 100);
    new3 = constrain(knob3.read(), -50, 50);
    new4 = constrain(knob4.read(), -100, 100);
  
    // If anything has changed in knobs
    if (new1 != position1 || new2 != position2 || new3 != position3 || new4 != position4) {
      setEnvelopeParams (new1, new2, new3, new4);
    }
  
    buttonMessages();
  
    // Update envelopes
    for(uint8_t i = 0; i<NUM_VOICES; i++){
      envelope[i].update();
    }
  
    // map it to values between 0.1 and about double the recorded pitch
    float pitch = (recorded_pitch * (float) 512 / 512.f) + 0.1f; 
  
    // set the sample playback frequency
    aSample.setFreq(pitch);
  
    // Clear trellis lights periodically
    if (lightDel.ready()) {
      for (uint8_t i=0; i < numKeys; i++) {
        trellis.clrLED(i);
      }
    }
  
    // Read Trellis input    
    if (trellis.readSwitches() ) {
      for (uint8_t i=0; i < numKeys; i++) {
        if (trellis.justPressed(i)) {
          // Illuminate LED
          trellis.setLED(i);
  
          // Play corresponding sample
          aSample.setTable(tables[i]);
          aSample.start();
  
          //samples[i].start();
          
        } 
      }
    }
    trellis.writeDisplay(); //Change LEDs
  }
  
  int updateAudio() {
    int knobsOut = oscilator[0].next() * envelope[0].next()
    + oscilator[1].next() * envelope[1].next()
    + oscilator[2].next() * envelope[2].next() >> 8;
   
    int trellisOut = aSample.next();
    
    
    return knobsOut;
  }
  
  void loop() {
    audioHook();
  }
