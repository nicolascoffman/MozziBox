#ifndef HH_open_H_
#define HH_open_H_
 
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <avr/pgmspace.h>
 
#define HH_open_NUM_CELLS 7228
#define HH_open_SAMPLERATE 16384
 
const int8_t __attribute__((section(".progmem.data"))) HH_open_DATA [] = {-2,
-2, 1, 1, -2, -2, 0, 1, -1, -1, 0, 0, 0, 0, -1, -1, -5, -5, -12, -13, -12, -13,
-6, -7, 33, 35, -80, -87, -40, -43, 21, 22, 30, 32, 29, 31, -23, -25, 8, 10, 40,
43, 13, 13, -73, -77, 39, 42, 18, 20, -19, -20, 11, 12, -4, -5, 12, 13, -56,
-60, -44, -50, 18, 20, -34, -37, -4, -4, 10, 12, -17, -20, 3, 4, -19, -19, 32,
34, -9, -11, -14, -13, 2, 3, -11, -11, -4, -6, 20, 22, 18, 21, 10, 8, 30, 32,
-23, -25, 10, 12, -29, -33, -11, -13, 0, 2, -38, -39, 12, 13, -5, -6, -3, 1,
-14, -20, 6, 11, -1, -2, 6, 2, -2, 0, -5, -9, 33, 42, -14, -20, -6, -3, 13, 11,
-4, -6, -5, -1, 1, -5, 0, 4, -2, -2, -1, -2, 3, 6, 3, 3, 17, 17, 1, 1, -5, -5,
12, 12, 5, 5, 12, 13, -5, -1, 9, 6, 4, 4, 12, 14, -4, -4, 0, -3, 30, 29, -3, 4,
3, -4, 8, 11, 15, 22, -11, -14, 2, 6, 6, 4, 2, 4, 13, 12, -18, -20, 9, 6, 12,
13, -10, -9, -5, -10, 13, 17, 11, 7, 2, 5, 6, 7, -7, -10, 4, 6, -9, -11, -16,
-16, 11, 15, 4, 3, -4, -4, -7, -8, 0, -1, 7, 12, -3, -7, 1, 5, 3, 6, 2, -2, -1,
3, -7, -6, 6, 5, 5, 5, 3, 3, -7, -7, 7, 2, 0, 3, -5, -5, 7, 5, 0, 2, 7, 7, -3,
-4, 0, 0, -3, -4, 7, 2, -2, 1, -6, -9, 5, 2, 3, 10, -13, -9, 3, -15, 2, -2, -2,
5, -3, 10, -15, -8, -3, -6, 6, 12, -8, -2, -10, -2, 18, -5, -4, 1, 1, 11, 1,
-13, 2, 2, 4, 2, -4, -6, -2, -12, 3, -9, -7, -4, -3, -2, -4, -4, -7, 3, 9, 9,
-6, 2, 1, 0, -6, 1, -3, 4, -4, -10, 0, 5, 3, -2, -4, -4, 4, 5, -7, -2, 3, 2, -6,
-4, 2, 6, 2, -7, -4, -5, 10, 3, -9, -9, 3, 1, 2, -3, -1, 3, 6, 8, -2, -2, 3, 1,
4, 7, -1, 2, 3, 7, 7, 5, 3, 7, -4, 3, 2, -3, 2, 0, 1, 4, 3, -1, -2, -3, 2, 4, 2,
1, 4, 3, -3, -3, 0, 1, -5, -5, -5, -5, 0, 1, -2, 0, -3, -2, 2, 2, -1, 1, 2, 1,
8, 8, -5, -8, -1, -3, 2, 3, -4, -6, 2, 9, -9, -5, 0, 2, 1, 1, -13, -7, 5, 5, 4,
-5, 7, 9, -2, -5, -2, -2, -2, -5, -1, -7, 0, 3, -8, -12, 10, 1, 0, -2, -4, -4,
-8, -8, -4, -4, 3, 5, -12, -7, -2, 1, -2, -3, -1, -4, 1, 1, 3, 5, -3, -1, 1, -3,
-3, 1, -7, 0, 2, 0, 1, 1, -2, -5, -3, -9, -1, 1, 6, 1, 2, 3, -13, -8, 0, -3, -5,
-3, -5, -7, -9, -7, 6, 2, 4, 3, -3, -1, 3, 4, -5, -3, 8, 7, -10, -5, -6, -3, 3,
4, 7, 6, -4, -3, -1, -1, 5, 0, -4, -3, 3, 6, -8, -11, 2, 1, -3, -1, -1, -6, -1,
-6, 0, 1, 1, 2, 0, 1, 0, 7, -1, 3, 7, 6, -2, 1, 2, 0, -3, -3, 4, 4, 5, 1, 0, 2,
-1, -1, 2, -1, 3, 1, -7, -10, 0, 0, 5, 1, 1, -2, -4, -7, 1, 0, 1, 3, -1, -5, -5,
-4, -1, 2, 3, 3, -5, -5, -3, -2, -4, 0, -2, 3, 2, 1, 1, -3, -3, -1, -1, 1, 0,
-2, -4, -7, -3, -3, -5, -3, -4, -2, 2, 1, -1, -2, 0, 1, 3, 2, -5, -2, -9, -7,
-5, -3, -5, -3, -6, -5, -6, -6, -3, -5, -2, -3, 0, -6, 0, -4, -4, -6, -4, -1,
-7, -7, -8, -7, -10, -11, -5, -8, -4, -8, -2, -2, 1, 1, -8, -8, -1, 2, -8, -5,
-2, 2, -2, -1, -6, -5, -1, -2, -3, -3, 6, -1, -9, -4, -7, -8, -2, 1, -6, 1, -10,
-6, -6, -2, -6, -9, -4, -4, 1, -4, -1, -5, 1, -1, -1, -1, 0, -2, -4, -3, 0, 1,
-3, 0, -3, -5, -1, -1, -3, -3, -5, -4, -1, -1, 1, 1, 0, -2, -2, -3, -6, -4, 3,
3, 1, 5, -2, -6, -4, -3, 5, 3, 5, 3, -3, -1, 2, 3, 2, 3, 9, 5, -2, -2, 1, -1, 5,
3, 4, 2, 2, 1, -5, -5, 5, 4, 0, 0, 2, 2, 3, 4, 0, -1, 4, 4, 2, 1, 4, 3, 3, 2, 6,
3, 3, 1, 2, 2, 5, 6, 3, 2, 3, 3, 2, 1, 1, 4, 2, 2, -5, -3, -1, 3, 1, 4, -1, 3,
1, 1, -3, -2, 9, 9, 4, 3, 3, 3, 4, 7, 2, 0, 4, 6, 0, 2, 2, 2, 1, 4, 4, 3, 1, 1,
3, 0, 2, 3, -3, -3, -1, -2, -6, -5, -2, -2, 0, 3, -6, -8, -1, -1, 1, 2, 0, -1,
-2, -3, 2, 5, 0, 5, 1, 4, 1, 1, 6, 1, 6, 5, 2, 1, 0, -2, -1, -1, 1, 3, -4, -1,
-3, -1, -6, -4, -1, 3, 0, 3, -2, -3, -1, 1, 3, 2, 2, 0, -1, -2, 1, -1, 1, 1, 2,
3, -4, -6, -1, 1, 5, 3, 1, 1, 2, -1, 2, 2, 3, 5, 0, -1, -1, 3, -3, -1, 2, 5, -1,
0, -4, -2, 0, 0, -3, -5, 2, 3, 0, 1, -2, -2, 0, 5, 1, 1, -2, -1, 4, 4, 1, -1, 1,
-1, 4, 0, -1, -1, 5, 2, 2, 4, -1, -2, 5, 4, 0, 2, -4, -3, 2, -1, -3, 0, 3, 0,
-2, -2, -3, -1, 5, 1, -2, -3, -4, -4, -3, -3, 5, 0, 2, -1, 0, -3, 4, 1, 0, -1,
2, 1, -1, 0, 2, 7, 3, 0, -1, 0, -1, 1, 4, 2, 1, 2, -3, -6, 5, 3, -4, -2, 0, 0,
2, -2, -8, -8, 1, -1, -5, -6, -1, -4, 1, 0, 2, -1, -2, -1, -2, -6, 4, 0, -6, -6,
-1, 0, -2, -1, -1, -1, -1, 0, -2, -4, -2, 0, 3, 2, -1, -2, -7, -6, -4, -5, 0,
-1, -3, -3, -3, -5, 0, -1, -3, -2, 4, 4, -10, -9, -1, 2, 2, 1, -3, -4, 0, 1, -6,
-6, 2, 4, 0, 0, -5, -3, 3, 3, -4, -2, -8, -8, 0, 0, -7, -5, -1, -4, -2, -5, -3,
-6, 2, 0, -2, -3, -6, -4, -3, -2, -1, 1, -3, 1, 2, 1, -4, -3, 3, 4, 2, 1, -4,
-3, 2, 4, -1, 1, -1, -1, 0, 2, -1, 0, -4, -2, 0, 1, -5, -4, -1, -1, -2, -1, -4,
-4, 4, 4, -1, 1, 1, 1, -3, -1, -2, -1, 0, -1, -1, -1, 1, 2, -1, -3, 0, 1, 0, -3,
-3, -3, 2, 0, 0, -4, -2, 0, 0, -1, -3, -5, 0, -1, -1, 0, -2, -2, -1, 0, -2, -3,
-5, -2, -1, -1, -3, -2, -3, 1, 2, 1, -3, -1, 4, 3, -2, -4, -1, 0, 2, 3, -3, -2,
3, 3, 2, 0, -1, 0, 3, -1, 1, -3, -6, -4, 0, -1, -4, -3, -3, -2, -2, -1, -4, -2,
-2, 0, -1, -4, -3, -1, 0, 2, 0, -3, -5, -4, 1, 1, 0, 1, -2, -1, -3, -5, -3, 0,
2, 0, 0, -3, -4, -7, 1, -1, -1, 0, -1, -4, -3, -1, -1, 1, 0, 1, -5, -5, -3, -1,
-1, 0, 0, 1, 1, 2, -3, -4, 1, 2, 0, 0, 3, 0, 4, 1, -4, -1, -1, -1, -1, -3, -3,
-4, -7, -6, 6, 5, -7, -5, 2, 3, -3, -7, -4, 1, 5, 3, -3, -6, 5, 8, 1, -2, 3, 5,
-3, 0, -1, -1, -1, 0, 5, 6, -3, 0, 1, 3, 3, -3, -6, -5, 3, 1, -3, -4, 1, 1, 3,
-2, -3, 1, 2, -2, -2, -1, -1, -2, 0, -3, -1, 2, -1, 1, 3, 2, -2, -2, 0, 3, 7, 4,
-6, -4, 3, 2, -1, 1, -2, -2, -1, -1, -3, -4, -2, -3, 0, 0, 1, -2, 1, 0, -1, -4,
3, 3, 0, -5, -5, -1, 3, 4, -3, -2, -1, 2, 0, -2, 2, 5, 5, 3, 6, 2, -5, -2, 3, 6,
4, 1, -7, -4, 1, 1, -2, -2, 5, 6, 0, -3, 1, 1, 2, -1, 0, -1, 1, 0, -4, -3, 2, 4,
0, -2, -1, -1, -3, -1, 0, -2, 1, 3, 2, 2, -2, -5, -1, 2, 3, 1, -5, -4, -3, 0,
-1, -1, 1, 2, 0, 0, -1, -3, 0, 0, 1, 1, 1, -1, -2, -2, -3, -3, 0, -1, -2, 1, -3,
-4, 1, 2, 3, 3, -1, -2, -1, 1, 2, -3, 2, 3, -2, 1, -1, -1, -1, 2, 1, 4, 2, 2,
-1, 1, 4, 3, 3, 0, -2, -2, -1, -1, 2, 1, -2, 1, 1, 3, -3, -2, -1, -1, 4, 3, 1,
0, 1, 0, 4, 4, 2, 0, 0, 1, 2, 3, -3, -3, 3, 2, -2, -2, -2, -3, 2, 2, -1, -3, 2,
1, 1, 0, 3, 1, 0, 0, 0, 1, -4, -3, 2, 3, 1, 0, 1, 2, 2, 3, -2, -4, 10, 11, -5,
-7, 0, 0, 0, 0, -1, 1, 0, 0, -6, -5, 2, 2, 1, 0, 1, 2, -3, -5, 1, 3, -2, -3, 3,
4, -3, -5, -1, 0, 4, 6, -2, -3, 1, 3, 1, 0, 5, 4, 3, 0, -1, -3, 1, -1, 2, 2, 1,
0, -2, -2, -3, -2, 4, 1, -4, -3, -3, -4, -3, -2, -2, -2, -2, -1, -9, -8, 2, 1,
-3, -2, -5, -4, -4, -4, -3, 0, -3, -1, -1, -2, -2, -1, -6, -7, 7, 6, -4, -4, -2,
-3, 6, 4, -5, -4, 3, 3, -1, -2, -1, 1, 1, 1, -1, 1, 0, -1, -3, -4, 0, 2, -4, -5,
1, 2, -5, -4, -1, 0, -1, -2, -6, -6, 5, 5, -5, -6, -2, -1, -1, -4, -2, 0, -3,
-1, -6, -6, 0, 3, -4, -3, 2, 4, -2, -2, -1, -2, 5, 3, -3, -3, 0, 0, 0, -3, -1,
-1, 0, 1, -2, 0, -3, -4, 4, 3, -2, -3, -3, -3, 3, 2, 0, -2, -2, -1, -1, 0, -8,
-8, 1, 2, 2, 4, -7, -7, 3, 3, -3, -4, 7, 5, -3, -4, 0, -2, 0, 3, -1, 0, -4, -3,
-4, -2, 4, 4, -2, 0, 0, -2, -4, -3, 3, 2, 0, -2, 0, 1, -3, -5, 1, 3, -2, -2, -2,
-2, -4, -3, 1, 1, 5, 3, -4, -4, 3, 3, -1, -3, 4, 5, -2, -3, 0, 0, 2, 3, 0, -3,
1, 0, -2, -3, 2, 2, -3, -3, 1, 0, -1, 0, 0, 2, -1, 0, -4, -3, 0, 0, -5, -5, 3,
4, 2, -1, 1, -1, 4, 5, -3, -4, -2, -2, -3, -3, -1, 2, -4, -3, -3, -5, -3, 1, 0,
-1, 0, 1, -3, -2, 1, -1, -4, 1, 3, 3, 2, 0, -2, 0, 2, 1, -1, -3, 2, 1, 3, 1, 9,
8, 0, 1, 0, -1, 3, 5, -6, -6, 1, 3, -3, 1, 0, -4, -7, -4, -1, -2, -1, -1, -3,
-1, 0, 0, -6, -4, -3, -4, 2, 1, -6, -2, 2, 1, 0, 1, -4, -4, 10, 6, -3, -1, 6, 2,
1, -2, 1, 3, -1, -3, 0, 0, -2, -1, -8, -7, 5, 4, -4, -5, 7, 6, -6, -5, 2, 3, 3,
4, -6, -3, 1, 0, -2, 2, 3, 3, -1, -1, -2, 1, 0, -2, 3, 4, -4, -4, 0, -1, -1, 0,
-1, 0, 0, -1, -6, -3, -2, -4, 2, 1, -3, -1, -2, -6, 0, 2, -3, -3, 5, 2, -4, 1,
4, 2, 3, 3, -4, -3, 3, 1, 0, 2, 4, 1, -1, -2, -1, 0, 3, 1, -2, 2, -3, -3, -3,
-2, -2, 0, -3, -6, -2, -2, 0, -1, 2, 0, 1, -1, -4, -3, 6, 2, 2, 4, 0, 0, 4, 4,
-9, -6, 3, 0, -1, 0, -1, -1, 1, -1, -3, 0, 2, 3, -6, -6, 1, 6, 3, 1, -4, -1, 0,
-2, -2, -6, -3, -1, 5, 1, -6, -6, 1, -1, 6, 5, -4, 0, -2, -4, -1, 0, 1, 3, 0,
-1, -6, -6, 0, 0, 10, 8, -9, -8, 1, 0, 0, -2, -3, -2, -1, -2, -8, -7, 1, 2, 3,
2, -4, -1, -6, -7, 4, 3, -1, 1, 4, 1, -1, 4, 2, 3, 2, 1, -7, -3, 4, 1, 0, -1, 2,
3, 3, 0, -1, 0, 3, 1, 3, 4, -1, -1, -2, -3, 0, 3, 5, 4, -6, -8, -2, -2, 5, 0,
-2, -3, 0, 2, 0, -4, 3, 5, 2, 2, -1, -2, -8, -6, 8, 7, -3, -3, -7, -6, 4, 4, -6,
-5, 4, 3, -7, -8, -4, 0, 4, 3, -3, -1, -2, 0, 1, -4, -2, 1, 5, 1, -3, -4, -1, 1,
8, 6, 0, 5, 0, 0, -3, -5, -2, 1, -5, -7, 0, 0, -6, -5, 3, -3, 0, 2, -2, -5, 0,
-1, 2, 2, 4, 3, -6, -2, 4, 2, -1, 0, 4, 5, -2, -4, -2, -4, 7, 11, 4, 1, -2, 1,
-2, 0, -3, -5, 2, 9, -2, -7, -8, -8, 2, 5, 0, -6, -4, -3, -5, -4, 5, 5, -2, 1,
-2, -2, -5, -4, -3, 0, 3, 1, -10, -8, 4, 2, 3, 2, 2, 5, 2, 0, -1, -2, 4, 4, -3,
-3, -2, 0, -1, -4, -1, 1, 1, 0, -4, -7, -4, -1, 3, 0, 3, 2, -4, -2, 1, 0, 2, 4,
-4, -4, -5, -8, -6, -5, 5, 3, -1, -2, -3, -3, 2, 2, -5, -1, 8, 10, -7, -7, 2, 5,
8, 7, -3, -5, 2, 3, 3, -1, 7, 8, 3, 3, 1, -3, -1, -1, 6, 5, -7, -6, -1, -2, -2,
-3, -3, -1, 1, 0, -9, -7, 2, 3, 4, 2, -9, -5, -1, -1, 0, -1, -3, 0, 5, 2, -8,
-8, 4, 3, 3, 0, 4, 2, -3, -5, -1, 0, 4, 7, -4, -5, -6, -1, -3, -2, 6, 4, -5, -2,
1, -3, -1, 0, 2, 1, 1, 0, -1, 1, 4, 5, -1, -1, 0, 1, -2, -2, 2, 0, 2, 5, 2, -3,
-3, 0, 5, 4, -1, -4, 0, 5, 1, 0, -4, -4, 3, 4, -4, -6, -1, -1, 1, 0, 1, 0, -3,
-3, 4, 5, -3, 1, 0, -1, 0, 2, -12, -11, 7, 5, -3, -4, -1, -2, 2, 1, -4, -3, 3,
4, -2, -3, -4, -2, 2, 1, 0, 2, -1, 1, -2, -3, -1, 0, -1, -3, -3, -4, 1, 3, -1,
-2, 3, 5, -2, -1, -2, -3, -1, 0, 1, -1, 0, 0, -2, -3, 0, -3, -2, -3, 3, 2, -6,
-6, 1, 4, 1, 4, -6, -4, 3, 5, -4, -4, -1, -1, 5, 3, -7, -7, 5, 5, 4, 4, -4, -4,
3, 3, -4, -4, -2, -3, 5, 5, -4, -3, 0, -3, 6, 5, -6, -7, -2, -1, 3, 2, -5, -5,
0, 3, 2, 0, -6, -6, 2, -2, -1, 0, -8, -9, 3, 0, 0, 0, -2, -2, 3, 8, -4, -6, -3,
3, -2, 3, -4, -6, -4, -1, 2, 1, -3, -7, 1, -2, 1, 2, -4, -9, 7, 10, -2, -6, -3,
-3, 1, 5, -4, -11, -4, 2, 3, 0, -3, -5, 0, 5, 3, -1, -4, -5, -3, 2, -1, -2, -3,
-3, 0, 1, 1, -4, -4, -7, 0, -2, -5, -7, 4, 3, 0, 2, -4, -2, 1, 0, -2, 1, -2, 1,
0, -2, 0, -1, -3, -3, 4, 3, -2, -5, -5, -4, 0, -1, -4, -4, -4, -2, 2, 1, -6, -2,
-1, -3, 1, 1, -4, -6, 3, 4, 0, 3, 0, -4, 2, 8, -2, 0, 0, 0, -3, -1, -3, -6, 2,
3, 0, -4, -2, -7, -3, -3, -2, -2, -3, -1, -3, -1, -1, -1, 1, 3, -1, -2, -5, -6,
2, 3, 2, -1, 0, 0, 2, 4, -1, -1, 0, 1, 2, 4, -1, 1, -2, -1, 2, 1, -3, -3, -4,
-4, 0, -2, 1, 0, -4, -2, -1, -3, 0, 4, -1, -3, 2, 1, -4, -1, 2, -4, 0, -1, 2, 0,
3, -3, -3, 0, 4, 5, -3, -2, -1, 2, 0, 3, -2, 3, 0, -4, -7, -4, -3, -7, -1, -2,
-3, 1, -1, -6, -2, -1, 3, 2, -3, -2, 2, 3, -3, -1, 3, 0, 1, 3, -6, -6, 7, 3, -5,
-2, 3, 0, -2, 1, 3, 6, 3, 3, -3, -3, 1, 4, 0, -4, 5, 3, -4, -4, -1, -6, 0, 2,
-3, 2, -2, -1, -1, 0, -1, 6, -2, -4, -1, -2, 1, 0, 3, -2, 0, -1, -4, -4, 4, 1,
2, 2, -1, 0, 0, 1, -4, 0, 6, 6, -2, -1, -4, -4, 2, 2, 0, 0, -2, 0, -2, -3, 1, 4,
2, 2, 3, 3, -5, -2, 0, -5, 5, 4, -2, -6, 1, -2, 4, 5, 5, 6, -1, 3, -3, 1, -1, 0,
0, 7, -1, 0, -3, -6, 5, 5, 3, -2, 2, 0, 0, 1, 2, -2, -1, -1, 2, 5, -1, -3, -6,
-4, 7, 5, -5, -6, -2, 0, 0, -4, 1, 3, 3, 4, -3, -5, -2, 7, 2, 1, -1, -1, -6, -3,
6, 3, 2, -1, 3, 1, 2, 0, 4, 2, 3, 6, -4, -2, 3, 3, 2, 6, 4, 5, 1, 2, 1, 1, 0,
-3, 3, 3, 0, 0, -1, 0, -2, -4, 3, 3, -6, -4, -4, -2, 2, -1, -4, -5, 6, 7, -4,
-8, 1, 3, 2, 2, -1, -1, 1, 6, 2, 3, -3, -3, -2, 0, 1, 0, -4, -6, 7, 4, -3, -4,
1, 1, 0, -2, -7, -4, -1, 1, -2, -1, 3, 6, -4, -5, -1, -3, 3, 2, 1, -4, 1, -1,
-3, -2, 3, 1, -1, -2, -1, 2, 0, 2, -4, -2, 1, 1, 0, -1, 1, 2, 0, -2, 0, 2, -2,
-3, -3, -1, -1, 2, -3, -4, -3, -1, 0, -2, 5, 3, -2, -7, -1, -8, 2, 2, -2, -3, 1,
2, -6, -1, -1, 1, -2, 1, -6, -4, -2, -2, -3, 0, 2, -1, -1, -6, -2, -1, 1, -2,
-2, -3, 0, 1, 0, 2, -4, -2, 3, 3, -2, -3, -7, -5, 1, -1, 0, -1, -2, -2, 1, 2,
-2, 0, 1, 1, -2, 1, -3, -2, 6, 2, -1, -2, 3, 0, -3, -7, 0, 1, 2, -1, -4, 2, -5,
-3, 0, 2, 0, 4, -3, -5, 0, 1, -3, -7, 9, 4, -3, -4, -1, -3, 1, -3, -1, 2, 0, -2,
-5, -1, 0, 3, -1, -5, -2, 4, -8, -10, -1, -6, -5, 2, -1, -3, -1, 0, -3, 2, 1,
-1, -5, -2, -4, -6, -1, -5, 2, 1, 0, -3, 2, -1, -3, -4, 0, 2, -5, -2, -6, -2,
-1, 1, -3, -1, -2, -2, -3, -4, 1, -3, -2, -7, -1, 0, -1, -6, 3, 3, -5, -5, -4,
-6, -4, -1, -3, -4, -1, 1, -6, -4, 2, -1, -1, 2, -3, 0, -4, -5, 1, 5, -4, -1,
-2, 1, 1, 1, 0, -4, 1, -3, -3, -9, 1, -4, 0, -1, 0, -3, -4, -1, -2, -1, -2, 0,
-3, 2, -4, -5, -3, -1, 2, 3, 3, 1, -3, -2, -1, 2, 2, -2, -1, 2, -1, -4, -3, -2,
-1, 1, 0, -4, 0, 4, -6, -11, 5, 5, -1, -1, 2, -1, -1, 4, -4, -3, 3, 3, -9, -5,
4, 1, 1, 1, 0, -1, 4, -3, 3, 4, -2, -3, 0, 1, -1, 2, -4, -2, -2, 2, -3, 1, 3, 1,
-1, 1, 4, 2, 4, -1, 2, 5, -1, -5, 5, 5, 2, 2, 3, 2, -5, 3, 3, 0, 2, 3, -8, -5,
3, -3, -5, -3, 4, 4, -2, -4, -1, 1, -3, -4, 0, 2, 0, 0, -3, -5, 1, 0, 0, -5, 6,
4, -4, -3, 2, 1, -1, 2, -3, 2, -1, 1, -3, 1, 2, 4, 1, -2, -3, 0, 2, -4, 5, 4, 1,
3, 3, -3, 1, 4, 4, 3, -3, -1, -4, -1, 0, -2, 2, 4, -2, 0, -2, -5, 3, 5, -3, -2,
5, 4, 0, 4, 1, -1, 1, 3, 1, -1, 0, -2, -2, -6, 7, 2, 2, 3, -2, -5, -1, 0, 0, 4,
-1, 1, -3, -3, -5, 0, 2, 1, 0, 0, 0, -1, 0, -6, 4, 8, 1, -3, 0, -1, 2, 3, -1,
-2, -2, 4, -7, -6, 1, -1, -2, 2, 2, 2, 1, -1, 1, 3, 3, 2, -4, -2, 2, 6, 0, 1,
-3, -3, 4, 5, 1, -2, 5, 1, 6, 1, 0, -1, 2, 3, 0, 0, 1, 5, -3, -1, 0, 4, -5, -3,
5, 2, 1, 5, 3, -4, 7, 4, -2, 1, 6, 1, -3, -4, 4, 2, -3, -2, -1, 2, 2, 0, 1, 1,
1, 2, 1, 0, 5, 6, 1, 1, 3, 3, -1, 4, 2, 4, -1, -4, 3, 6, 0, -1, 2, -5, 2, -1,
-1, -4, 4, 1, 0, 2, -2, 0, -4, 1, -1, 2, -7, -2, -2, -1, -3, -3, 0, 2, 3, -4,
-4, -2, 0, 1, 4, 1, 1, -1, 1, -1, 3, 6, -1, -2, 8, 3, -4, -3, -2, -1, 4, 1, -5,
-3, 1, 4, -3, -4, -3, 3, -3, -4, -2, -2, -4, -1, 4, -1, 2, -3, 1, -1, 2, 3, 1,
-4, 1, 2, -5, -2, -2, 0, -3, 0, -2, 1, -3, -3, -1, 0, 0, -2, -3, -7, -2, 0, -1,
-4, -4, -6, -1, -1, -5, -3, -1, 3, -1, -2, -5, -5, -1, 2, -3, -2, 1, -1, -1, -1,
0, 2, -5, -1, 0, 1, -4, -5, -6, -3, 2, 0, -6, -11, 1, -4, 0, -2, -2, -2, -2, -4,
-4, 0, -2, 2, 1, 1, -2, 2, -4, -4, 2, 3, 0, -1, 0, -6, 5, 3, 4, 3, -1, -2, 1,
-4, -2, -3, -5, 0, -5, -3, 1, -2, -5, -2, 0, 2, -2, -4, -1, 0, 6, 4, -6, -4, 5,
7, -2, -4, -3, -3, -1, 0, 0, -6, -1, -5, 0, -5, 2, 1, 0, -1, 0, 2, -3, 3, -1, 0,
-5, 0, -1, 1, -4, -5, -1, 2, -2, -6, 2, -3, 0, 4, 0, -3, 4, 1, -2, -2, 0, 2, -5,
-1, -1, -1, -2, -3, -1, 3, -2, -3, -1, 0, 1, 6, -6, -6, 0, 4, -4, -4, -3, -2, 1,
1, -3, -6, -2, -6, 4, -3, 1, 0, -3, -3, 2, -2, -2, 4, 1, 2, -4, -4, -2, 2, -1,
-2, -2, -1, -3, -2, 2, -5, -2, -1, -2, 1, -2, -5, -4, -5, 2, -1, -8, -4, -2, -1,
-4, -7, -3, -1, -1, 1, -1, -4, -1, 2, 1, 1, -3, 0, -2, -1, -1, 1, -6, -1, 2, -2,
-4, -5, 2, -5, 2, -3, -2, -2, 3, 2, -2, -2, -5, 1, 0, 1, -4, -2, -4, -1, -1, -2,
-6, -2, -2, -5, 2, -2, -1, 2, 3, -2, 0, -2, 1, -1, 2, 1, -3, 1, 2, -1, -2, -2,
-2, 3, -2, -6, -3, -2, 5, 9, 1, -1, -1, 5, 3, 2, -1, 2, 0, 1, -1, -5, -1, -3, 4,
-3, 1, 0, -1, -2, 0, 0, 2, 5, -2, 2, -2, -1, -3, 1, -2, 1, -1, -2, -1, 1, 3, -2,
-4, -5, 5, 6, 1, -4, -3, -1, 4, 3, 0, 0, -3, 4, 3, -1, -1, 1, -2, 1, 3, 1, -6,
-3, 2, 1, -1, 1, 1, 4, 3, 5, -4, -2, 1, 2, 0, -2, 2, -6, 1, 0, 5, 2, 3, 3, 0, 2,
1, 3, -2, -1, 2, 6, -1, 2, -1, -4, 1, 2, 0, -1, 3, -3, 1, 1, 0, -1, 2, -3, 0, 1,
0, -2, -3, 1, 0, 2, -3, -5, -1, 2, 2, 2, -3, -3, 2, 4, -2, -1, 0, 0, -2, 2, 0,
1, 0, 0, -2, -2, 0, -5, 3, -3, 3, 1, 1, -1, -1, 1, -2, 1, 2, 5, -4, 2, -1, 1,
-1, 1, 0, -1, 3, 4, -3, -8, 0, 0, 2, 4, -2, -6, -1, 0, -3, -5, 1, 1, -1, 4, 0,
-5, 0, 1, -2, 0, -1, -2, -4, -1, 0, 0, 0, 4, 3, 5, -1, 3, 1, 0, 3, 1, 5, 4, 7,
-2, 2, -3, 2, 0, 1, 1, 5, 6, -1, 1, 0, 3, 2, 4, 0, 2, -1, -1, 0, 0, 1, 0, 1, -5,
0, 0, -2, -2, 2, -1, 0, -2, 2, 0, -3, 2, 0, -1, 0, 0, -2, 0, 2, 2, -5, -2, 2, 2,
2, 4, -4, -2, 2, 4, 2, 2, -1, -1, 1, 2, 2, -3, 3, -4, 3, 1, -1, -2, -1, -2, 1,
3, -4, 0, -6, -1, 0, 1, -4, -2, 1, 1, -1, 1, 2, -4, 6, 0, -3, 0, 5, -1, -3, -5,
1, -2, 0, -1, -6, 2, -1, -5, -5, -6, -1, 4, -2, -1, -2, -1, -1, 1, -2, 0, -1, 1,
1, 2, -2, -4, 1, 3, 0, -3, 0, -9, 1, -1, -2, -3, 0, -1, -4, -1, -6, -3, -6, 0,
-6, -2, -7, -3, -1, -1, -3, -3, -2, -1, 3, -6, -2, 0, 0, 0, 1, -4, 2, 2, 1, -1,
-5, -1, -2, 0, 1, -2, -1, 2, -3, -3, -4, -4, 1, 2, -4, -2, -4, -1, 0, 0, -3, 0,
1, 1, -2, -3, -2, -8, 6, -2, 0, -2, -1, -2, 1, 1, -4, -2, -3, 2, -5, 0, -1, 0,
-2, 0, -2, -4, -2, -1, 1, -5, 2, -4, -2, 1, 4, -2, -3, -5, 2, 0, -4, -3, -3, 2,
3, -1, -2, -1, -4, 0, -1, -3, -1, 1, 0, 2, 2, 4, -2, -1, -1, 1, -7, -4, 3, 2,
-3, -5, 5, -3, 3, -2, -3, -5, 0, -1, 1, 1, -1, 2, -6, -1, -1, 0, -4, 2, 1, 3,
-3, -4, 2, 3, 3, -5, 3, 1, 0, 0, 0, -6, 4, 2, 3, 2, -5, -3, -2, 0, 2, -2, -1, 1,
3, 4, -3, -3, 1, 5, 3, 3, -3, 0, -1, 1, 2, 4, 0, 0, 0, 0, 0, -7, 3, -3, 3, -1,
1, -1, -3, 0, -3, -3, -1, 3, -9, -4, -7, -4, 3, 4, -4, -3, -1, 0, 0, -3, -1, -6,
4, 8, 0, -4, -1, -1, 4, 5, -2, -6, -5, 4, 1, -1, -1, -4, 0, 4, -1, -1, -3, -2,
2, 5, -4, -2, -2, -1, -1, 4, -4, -2, 6, 5, -6, -5, 4, -5, 6, -1, 0, -3, 3, 1,
-1, 2, 1, 2, -4, 0, -3, 2, -4, -1, 0, 1, -1, -1, -1, 0, 1, -5, 5, 2, -2, -1, 1,
-4, -1, -2, -2, -2, 0, 3, -4, -1, -1, -3, -1, -1, 2, 3, -3, -5, 7, 6, -1, 2, 0,
2, 0, 1, -5, -2, -1, -1, -3, -3, 3, 0, 3, -6, 4, 3, -1, -2, -1, 0, 0, 2, 1, 3,
-4, 2, -3, 0, 1, 3, -4, -4, 4, 3, 2, -2, 1, -5, 1, 2, 1, -1, 1, -2, 1, -1, -2,
-5, -2, 6, -3, -2, -1, -5, 0, 3, -4, -4, 2, 3, 0, 0, -3, -1, 0, 3, -2, 0, -1,
-3, 4, 2, -1, -2, 4, -5, 4, -5, 1, 0, 2, 0, -3, -1, 2, 4, -6, -1, -4, 0, 1, 5,
-5, -2, 0, -2, 1, 3, 1, -7, 3, 1, -1, 2, -1, -6, -1, -1, -1, -2, -5, -3, -4, 0,
3, -2, -4, -3, -1, 4, -1, 0, -2, 0, 0, 3, -4, -2, -1, 1, -6, -3, 3, 1, -2, 0, 0,
-5, 6, -5, -1, -4, 4, 0, 1, -1, -3, -2, 0, 3, -6, -1, -4, 0, 1, 5, -3, -2, 3, 6,
0, -2, 4, -3, 2, 5, 2, 0, 1, -1, 3, -1, -1, -2, -4, 3, 2, 1, -2, -6, 1, 2, -4,
-1, 2, 1, -2, -3, 1, 3, -2, 0, -4, -2, 2, 4, -3, -5, 1, 3, 1, -7, 6, -4, 4, 4,
1, -3, -1, 1, 0, 1, -4, 1, -4, 2, -2, 1, -3, -1, -1, 1, -2, -1, 1, -7, 5, 4, -1,
1, 1, -3, 6, 3, 0, -4, 3, 6, -6, -1, 3, -1, 1, 1, -2, 2, -1, 2, -4, -3, 6, 8,
-6, -3, 0, 0, 1, 3, 0, -2, 2, 2, -4, -6, 6, -7, 0, -4, 2, 2, -2, -5, -4, -2, 1,
3, -9, -2, -1, 3, -1, -1, -4, -1, 1, 4, -1, -5, 5, -4, 1, 3, -1, -2, 0, -4, 2,
-1, 0, -1, -8, -2, 1, 1, -1, -4, 0, 1, -4, -1, 0, 1, 2, 0, -6, 0, -3, 0, -3, -3,
1, 5, -5, -6, -3, 0, 1, -7, 1, -8, 4, 4, 0, -3, 1, 1, 2, 3, -6, -3, -5, 1, -4,
-3, -3, 0, -1, 0, 0, 0, 2, -3, 5, -1, 1, 4, -1, -6, 4, -1, -1, -3, -1, -1, -4,
2, -2, -5, 2, -1, -2, 2, -1, 1, 2, 1, 1, 3, -4, 0, 1, -1, -2, 2, -3, -2, 2, 3,
-2, -2, 3, -11, 2, 0, -1, -1, 2, -1, -2, 2, -3, 0, -3, 3, -6, 0, -1, 1, -5, -1,
-1, 0, -1, -2, 4, -2, 3, 3, -1, -1, 7, 1, -3, -4, 0, -4, -6, -1, -4, -2, 2, -2,
-4, -3, -3, 1, -2, -2, 2, 4, -2, 3, -5, -5, 3, 6, 1, 2, 0, 1, 5, 4, 3, -4, 8,
-1, 2, 0, 0, -3, -2, -2, 1, 3, -1, 0, -10, -1, -1, 0, -4, -1, -1, 1, -1, -2, 1,
-4, 3, 0, 0, 2, 3, 0, 0, -3, 5, 4, 0, 1, -2, 2, 1, 0, -1, -4, -1, 4, 0, -1, 0,
0, -2, 3, 0, 1, -2, -1, -3, 0, 0, 0, -5, -5, 2, 1, 3, -9, 2, -5, 1, 2, 0, -2, 3,
5, -5, -1, -1, 3, -5, 1, 1, 5, -5, -3, -3, -2, 0, 2, -1, -9, 4, 3, -2, 0, 3, -4,
-3, -2, 1, -4, -3, 1, -2, 3, 5, 1, -2, -2, 2, 6, 0, 2, 0, -1, 3, 6, -5, -4, 3,
4, 1, 2, -4, -5, -3, -1, -1, -9, 6, -6, -2, -1, 0, -3, 1, 5, -2, 0, -1, 3, -9,
-1, -1, -1, -4, 3, 0, -1, 2, 3, 0, -1, 6, 0, -1, 2, 3, -2, 2, -1, 1, -1, 2, -1,
-5, 3, 2, -3, -3, -5, -2, 2, 0, 2, -6, -3, 3, 4, -5, 0, -1, 0, 1, 4, -2, -3, 3,
2, -2, -2, 7, -8, 4, -2, 0, 0, 3, -3, -4, 1, -2, -1, -5, -3, -6, 4, -2, -2, -1,
0, -1, 1, 3, 2, 2, -4, 1, -1, 1, 4, 2, -4, 3, 3, 4, -1, -4, -2, 0, 5, 1, -3, -2,
-1, 2, 4, -4, -2, 1, 2, -4, 0, -4, -1, -2, -2, 1, 5, -2, -3, -2, -2, -1, -4, 3,
-12, 1, 1, -4, -5, 4, 3, -4, 0, -2, -2, -6, 2, -5, 0, 1, 2, -1, 0, -2, 1, -2,
-5, 2, -4, -3, 0, -3, -4, 2, -1, 0, -2, -1, -2, -5, -1, -3, -3, 3, 1, -1, 1, -3,
1, -3, -2, 4, 7, -1, 3, -6, -5, 7, 7, 0, 0, 2, -1, 1, 0, 2, -10, 9, -1, -6, -5,
-1, -3, -2, 2, 0, 1, -2, 0, -6, 1, 1, 3, -2, 1, -1, 0, -3, -5, 2, -4, 3, 0, 0,
1, -2, -6, 0, 0, 3, -1, -1, 1, -5, 1, 1, -3, -2, -2, -4, 0, -3, 1, -2, -3, 1, 6,
-4, -1, -3, -2, 2, 4, 0, -1, -1, -1, 3, -2, 7, -9, 2, -1, 2, 2, 3, -1, 2, 8, 2,
3, -5, 1, -4, 3, -2, -1, 0, 3, -4, -3, -3, -4, 7, -1, 1, 3, 1, 1, 3, -4, 2, 1,
0, -3, 0, 7, -2, -3, 1, -1, 1, 2, -4, -1, 1, 4, -1, -2, -1, 6, -2, -2, -2, -2,
-2, 2, -1, -3, -1, 0, 3, -7, 1, -10, -2, 0, 4, 2, -3, 2, -1, 1, -2, -1, -10, 1,
-2, 0, -3, -3, -5, -2, -1, 1, -1, -8, 3, 1, -1, 4, 0, -7, -1, -1, -2, -6, -1,
-1, -5, 3, 0, -4, -1, -2, 0, 4, -2, 1, -3, -2, -1, 6, -6, -2, -1, -2, -1, 2, -2,
-2, -1, -4, 0, -2, 8, -9, -1, -6, 3, 4, 3, -1, -5, 3, 1, -3, -8, 0, 0, 7, -1, 0,
-2, 0, -1, -1, -5, -4, 4, -4, 3, 5, 0, -1, 1, -2, 5, 1, -2, -6, -1, 4, 0, 1, -1,
-3, 2, 3, -1, 0, -3, 1, -1, 1, -5, 2, -4, -1, 3, 2, -6, 2, 0, -2, 3, 3, 2, -5,
6, -7, 2, 3, 3, -1, 0, 4, 2, 3, -4, -3, -2, 7, 0, 2, -2, 2, 2, 4, 0, 0, 1, -3,
5, 0, 0, 2, 1, -5, 2, 0, 2, 0, 5, 3, -8, -3, 4, 2, -2, -3, 1, 3, 1, 4, -4, -3,
6, 8, -5, 1, 4, 1, -2, -2, 2, 4, 0, -2, 1, -1, 6, -8, 1, -3, 6, 6, -1, -3, 1, 8,
0, -2, -5, 1, -6, 1, -1, 2, -2, 2, 0, -1, 0, 0, 1, -7, 3, 2, 0, 1, -1, -8, -1,
-3, 4, 2, -5, 0, -4, -2, 1, -1, -3, -1, 0, 1, -5, -2, -1, 0, 3, 9, -4, 0, -1,
-3, -2, 2, 2, 2, 1, 0, 1, -6, 7, -6, 0, -2, 1, -3, -1, 3, -2, 2, -4, -7, -8, 4,
-2, 3, -5, -3, 0, 0, -4, -4, -1, -5, 6, -1, -2, 0, 3, -3, 0, -2, 1, -1, -1, -5,
-5, 3, 3, 2, -4, -7, 1, 4, -3, -1, -3, 1, 0, 3, -5, 0, 3, 3, -4, 1, -2, 1, 4,
-2, 0, 2, 4, -10, 6, -2, -1, 2, 4, 2, -3, 5, 0, -2, -6, 3, -4, 5, -3, -1, -6,
-1, 6, 4, -5, -4, 8, -2, 0, -2, -5, -3, 7, -1, -5, -5, 2, -6, -6, -5, -5, -2, 1,
-1, -3, -4, 1, 3, -7, 0, 2, 0, -3, 2, -7, -4, 1, -3, -2, 3, 3, 0, 0, -3, 3, -3,
7, -7, 1, -1, 6, 4, -1, 4, 4, 4, -2, -1, -5, 7, -1, 1, 0, 5, 5, 6, -6, -7, 5, 4,
-1, -9, 3, 5, 1, -2, -2, -5, 2, -1, -4, -10, -6, 4, -2, -5, -2, -4, -4, 0, 0, 1,
-5, 0, 0, 1, -4, 2, -6, -8, 0, 3, -2, -1, -1, -2, 1, 2, 3, -14, 1, -4, 0, -1, 1,
-1, -5, 1, 0, -1, -3, 2, -5, 3, 0, 4, -2, 0, 4, 4, -5, -2, 4, -3, 5, 0, -4, -3,
5, -2, -4, -5, 4, -2, -3, 0, -3, 1, 4, 1, -5, -5, -2, -1, -7, -1, 3, 3, -1, 3,
-4, -1, 1, 0, -2, 2, 2, 1, 0, 2, 3, -1, 4, -14, 3, 2, 1, -2, 0, 3, 1, 5, 0, -7,
-4, 12, -4, 1, 1, 2, -1, 3, -5, -4, 3, 2, 6, -2, 0, 3, 0, -3, -2, -6, 2, 0, 0,
-4, -5, -1, 0, 1, -2, -4, -3, -5, -2, 1, -3, 0, 3, 4, -4, 2, -1, -2, 2, 3, -4,
1, 4, -2, -2, 1, 7, -4, 4, -7, 0, 4, 3, 1, -5, 1, 3, 1, -5, -2, -4, 6, 1, 1, -4,
-2, 4, 4, -1, -1, 2, -5, 4, 0, 0, 1, 2, -3, 1, 0, 1, -4, -7, -5, 0, 4, -3, -4,
0, 0, -1, 0, -7, -1, 2, 1, -3, 0, -5, 3, 1, -4, -1, 1, 0, 1, 2, 1, 0, -3, 4,
-10, 3, 2, 0, -1, 0, 3, -3, 1, -4, -5, -4, 6, -5, 0, -4, 1, -1, 0, -2, 0, -2,
-4, 2, -4, 0, 3, 1, -4, -2, -4, -1, -2, 2, -6, -6, 1, 0, 0, -2, -5, -2, -1, 1,
2, -5, -1, 0, -1, -5, 2, -2, -2, 1, -1, -2, 2, 3, 0, -2, -2, 2, -7, 3, -6, -1,
0, 1, -1, -1, 2, -2, -3, 0, 0, -7, 1, -3, -1, -1, 3, 2, 0, -1, 2, 1, -3, 6, 1,
-2, 3, 1, -6, 1, 0, 3, -1, -2, -2, -1, 2, 2, 0, -2, 1, -1, -2, -1, 2, -1, -1, 2,
6, -2, -1, -1, -3, 2, 4, -3, -3, 1, 0, -2, -5, 4, -5, 2, -2, 1, 0, -1, 0, -3, 2,
2, -2, -8, 1, -3, 3, -1, 0, 2, 5, -3, -3, -3, -2, 4, -2, 0, 0, 2, 0, 0, -4, 2,
2, 2, -2, -2, 0, -2, 0, 1, -1, 0, 0, 0, 1, -4, -2, 1, 1, -3, 2, -6, -5, 0, 0,
-1, 1, 1, -2, -3, -1, 1, -8, 3, -7, 0, 2, 0, -3, -1, 4, 0, -2, -1, 1, -5, 4, -3,
-3, -1, 3, -2, -1, -1, 0, -2, -3, 3, -1, -2, 0, -1, -4, 1, 0, 0, -2, 1, -2, -5,
1, 1, -1, -2, -3, -1, 0, 0, 2, -1, 1, 1, 2, -3, 2, -1, -4, 0, 1, -1, 1, -1, -2,
0, 0, 5, -7, 0, -1, -1, -1, 0, -1, -2, 4, 2, -3, -5, 1, -2, 2, -1, 0, 1, 3, -1,
-2, -1, 0, 4, 1, 3, 3, 1, 1, -1, -4, 0, 0, 2, -2, -2, 1, -1, 0, 2, 1, -2, -1, 0,
1, -4, -1, 3, 2, 2, 7, -3, -3, 2, -1, 0, 4, 1, -1, 2, 1, 1, -4, 3, -4, 2, 2, -1,
-1, -1, 3, -1, 0, 0, -1, -5, 3, -2, 0, -2, -1, 0, 1, 0, -1, -2, -2, 5, 0, -2,
-1, 2, 0, 0, -2, 0, -2, 1, -1, -3, 0, 1, -1, -2, -2, 1, 0, -4, -2, 0, 1, -2, 0,
-4, 0, 0, -1, -3, -2, 0, 1, 0, -3, 0, -2, 2, -5, 2, -2, 0, 0, 0, 0, -2, 2, 0,
-3, -2, 1, -3, 2, -1, -1, -1, 1, -2, -1, -2, -1, 3, 0, -1, -2, 1, 1, 0, -3, -1,
-1, 2, 0, -1, 0, -2, 0, 0, -1, 0, -1, -2, -1, -1, 1, -2, -2, 0, 2, -1, -1, -1,
-3, -1, 1, 0, -2, 0, 0, -1, -3, 3, -5, -1, 1, 1, 0, -1, 1, -2, -1, 0, -1, -4, 3,
0, 2, -2, 1, -1, -1, 2, 2, -2, -2, 2, -2, 2, 2, 0, -1, 0, -1, 0, -2, 0, -2, -2,
1, -1, 0, -1, -1, 0, 0, -1, 1, -2, 0, 0, 0, -3, 2, 0, -2, 1, 0, -2, 0, 1, -1, 0,
-1, 2, -4, 2, -2, -1, 0, 2, 1, -1, 2, 1, -1, -2, -1, -1, 4, -2, -1, -1, 0, 2, 2,
-3, -3, 2, 0, 1, -1, 0, 0, 1, -1, -2, -2, 1, -1, -2, -1, -1, 1, 0, -1, -2, -1,
0, 0, -3, 0, -1, 0, -1, 2, -2, 0, 0, -3, -2, 0, 1, 1, 0, -2, 0, -2, 1, -4, -1,
-1, 1, -1, -1, 1, -2, -1, 0, -3, -2, 2, -2, 0, 0, 0, -1, 0, 0, -1, 0, 0, -1, -2,
0, 1, -1, -2, 0, -1, -1, -2, 0, -2, -1, 2, -1, -2, -1, -1, -1, -1, 0, 0, -3, -1,
-1, 0, -1, 1, -2, -3, 1, 0, -1, 1, 0, -1, 1, 0, 1, -3, 1, -2, -1, 0, 1, 0, -1,
1, -1, -3, -1, 0, -3, 1, 0, 1, -2, -1, 0, -1, -2, -1, 0, -1, 0, -1, -1, -1, 1,
-1, -1, 0, 0, -1, -1, -1, -1, 0, -1, -1, -1, -1, 0, 0, -2, 0, -1, 0, 0, 1, -2,
0, 1, -1, 0, 1, 0, 0, 1, 0, 0, -1, 2, -3, 0, -1, 1, 0, -1, 0, 0, 1, 0, -2, -2,
1, -1, 1, -2, 0, 0, 0, 0, -1, -1, 0, 1, -1, 0, -1, 0, -1, 0, -1, 0, 0, 1, -1,
-1, 0, 0, 0, 0, -1, -1, -1, 0, 0, -1, 1, 0, 0, -2, 1, 0, 0, 0, -1, -1, 1, 0, 0,
-1, -1, 1, -2, 0, -2, -1, -1, 0, -1, -1, 1, -1, -2, -1, -1, -2, 1, -1, 0, -1, 0,
0, -1, -1, -1, -1, -1, 1, -1, -1, 0, 0, -2, -1, -1, 0, -1, 0, -1, -2, 0, 0, -1,
-1, 0, -1, -1, -1, 0, -2, 0, 0, 0, -1, 0, -1, -2, -1, 0, -1, 0, 0, -1, 0, -1, 1,
-2, -1, -1, 0, -1, 0, 1, -2, -1, 0, -2, -2, 0, -1, 0, -1, 0, -1, 0, 0, -1, -1,
0, 0, -1, 0, 0, -1, -1, 0, -1, 0, 0, 0, -1, -1, -1, 0, 0, -1, -1, -1, 0, 0, 0,
-2, 0, 0, 0, -1, 0, -1, -1, 0, -1, -1, 0, 0, -1, -1, -1, 0, -1, 0, -2, -1, 0, 0,
0, -1, 0, 0, -1, 0, -1, -1, 1, 0, 0, -1, 0, 0, 0, -1, -1, 0, 0, 1, 0, 0, 0, 0,
-1, 0, 0, 0, -1, 0, -1, -1, 0, 0, -1, 0, 0, 0, -1, -1, 0, -1, 0, 0, 0, -1, 0, 0,
-1, 0, 0, -1, 0, 0, -1, 0, 0, 0, -2, 0, -1, -1, -1, 0, 0, -1, 0, 0, -1, -1, 0,
-1, 0, -1, 0, -1, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0,
-1, 0, 0, -1, -1, 0, 0, 0, -1, 0, -1, 0, -1, 0, -1, -1, 0, -1, -1, 0, 0, -1, -1,
-1, 0, -1, 0, -1, -1, -1, 0, 0, -1, 0, -1, -1, 0, -1, -1, 0, -1, 0, -1, -1, 0,
0, 0, -1, -1, 0, 0, -1, -1, 0, 0, -1, 0, -1, 0, 0, 0, -1, -1, 0, 0, -1, -1, 0,
-1, 0, -1, -1, -1, 0, 0, 0, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1, -1, -1, 0, -1,
0, -1, 0, -1, -1, 0, -1, 0, 0, -1, -1, 0, -1, 0, };

#endif /* HH_open_H_ */
