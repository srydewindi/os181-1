/*
 * Copyright (C) 2016-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV04 Mon Mar 12 17:33:30 WIB 2018
 * START Mon Oct  3 09:26:51 WIB 2016
 */

#define MSIZE0 0x10000
#define MSIZE1 0x10008
#define MSIZE2 0x10009
#define MSIZE3 0x1000A
#define MSIZE4 0x10010
#define MSIZE5 0xA0000
#define MSIZE6 0x100000
#define MSIZE7 0x10000000
#define MSIZE8 0x10000000
#define MSIZE9 0x10000000
#define LINE   75
#define MAXSTR 80
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

void printLine(int line) {
   while(line-- > 0) putchar('x');
   putchar('\n');
   fflush(NULL);
}

void main (void) {
   int   msize[]    = {MSIZE0, MSIZE1, MSIZE2, MSIZE3, MSIZE4, 
                       MSIZE5, MSIZE6, MSIZE7, MSIZE8, MSIZE9};
   int   ii, myPID  = (int) getpid();
   char  strSYS1[MAXSTR], strOUT[MAXSTR];
   char* chrStr     = strSYS1;

   printLine(LINE);
   sprintf(strSYS1, "top -b -n 1 -p%d | tail -5", myPID);
   system (strSYS1);
   sprintf(strSYS1, "top -b -n 1 -p%d | tail -1", myPID);
   for (ii=0; ii< (sizeof(msize)/sizeof(int)); ii++){
      chrStr = malloc(msize[ii]);
      fgets(strOUT, sizeof(strOUT)-1, popen(strSYS1, "r"));
      strOUT[(int) strlen(strOUT)-1]='\0';
      printf("%s [%X]\n", strOUT, msize[ii]);
      free(chrStr);
   }
}

//
//   chrStr = malloc(MSIZE1);
//   system(strSYS2);         /* (3) */
//   free(chrStr);
//   chrStr = malloc(MSIZE2);
//   system(strSYS2);         /* (4) */
//   free(chrStr);
//   chrStr = malloc(MSIZE3);
//   system(strSYS2);         /* (5) */
//   free(chrStr);
//   chrStr = malloc(MSIZE4);
//   for (ii = 0; ii < MSIZE4; ii++) {
//      chrStr[ii]='a';
//   }
//   system(strSYS2);         /* (6) */
//   free(chrStr);
//   chrStr = malloc(MSIZE5);
//   system(strSYS2);         /* (7) */
//   free(chrStr);
//   chrStr = malloc(MSIZE0);
//   for (ii = 0; ii < MSIZE0; ii++) {
//      chrStr[ii]='a';
//   }
//   system(strSYS2);         /* (8) */
//   free(chrStr);
//   printLine(LINE);
//
