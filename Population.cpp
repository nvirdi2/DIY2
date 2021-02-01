
//Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: Jan 31, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>

#include "Population.h"
#include "File.h"
#include "cstring.h"
#include <cstdio>
using namespace std;

namespace sdds 
{

	int postalCodeNo;
	PopulationPC* postalcodePOP;


    void strCpy(char* des, const char* src)
    {
        while ((*des++ = *src++));
    }

   
    int strLen(const char* s)
    {
        int lenght = 0;
        int x;

        for (x = 0; s[x] != 0; x++)
        {
            lenght++;
        } return (lenght);
    }
	
	void deallocateMemory() {
		for (int x = 0; x < postalCodeNo; x++) {
			//RETURN NOTHING
		}
	}


	bool load(PopulationPC &postalCodePop) {

		bool ok = false;

		char postalCode[20];
	
		if (read(postalCode)) {

			if (read(postalCodePop.Population)) {

				postalCodePop.PostalCode = new char[strLen(postalCode) + 1];
				strCpy(postalCodePop.PostalCode, postalCode);

				ok = true;
			}
		} return ok
	}


	bool load(const char *file) {
		bool ok = false;

		if (openFile(file)) {

			postalCodeNo = noOfRecords();
			postalcodePOP = new PopulationPC[postalCodeNo];

			for (int x = 0; x < postalCodeNo; x++) {

				if (!load(postalcodePOP[x])) {

					cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
					closeFile();
					return false;
				}
			}
			closeFile();
			ok = true;

		}
		else {
			cout << "Could not open data file: " << file << endl;
		} return ok;
	}


	void sort() {
		PopulationPC temporary;

		for (int x = postalCodeNo - 1; x > 0; x--) {

			for (int y = 0; y < x; y++) {

				if (postalcodePOP[y].Population > postalcodePOP[y + 1].Population) {

					temporary = postalcodePOP[y];

					postalcodePOP[y] = postalcodePOP[y + 1];

					postalcodePOP[y + 1] = temporary;
				}
			}
		}
	}

	
	void display() {
	cout << "EPostal Code: population" << endl;
	cout << "-------------------------" << endl;

		sort();

	for (int number = 0; number < postalCodeNo; number++) {
		
		cout << number + 1 << "- ";
		display(postalcodePOP[number]);

		}	

		cout << "-------------------------" << endl;
	}
	
	
	void display(const PopulationPC& postalcodePOP) {
		cout << postalcodePOP.PostalCode << ": " << postalcodePOP.Population << endl;
	}


}
