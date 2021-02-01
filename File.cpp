/// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: Jan 31, 2021

//I have done all the coding by myself with the help of the LAB 

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

#include <iostream>

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   bool read(int &Population)
	{
		bool done = fscanf(fptr, "%d\n", &Population);
		return done;
	}

   bool read(char* postalCode)
	{
		bool done = fscanf(fptr, "%3s,", postalCode);
		return done;
	}
}
