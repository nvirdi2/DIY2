/// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: Jan 31, 2021

//I have done all the coding by myself with the help of the LAB 

#include <iostream>

#include "Population.h"
#include "File.h"
#include "cstring.h"

using namespace std;

namespace sdds 
{

	int postalCodeNo;
	PopPC* postalcodePOP;
	int popTotal;

	void strCpy(char* des, const char* src)
    {
        while ((*des++ = *src++));
    }

	int strLen(const char* s)
    {
        int lenght = 0;
        int i;

        for (i = 0; s[i] != 0; i++)
        {
            lenght++;
        } return (lenght);
    }


	void deallocateMemory() {
		for (int i = 0; i < postalCodeNo; i++) {
			//RETURN NOTHING
		}
	}


	bool load(PopPC &postalCodePop) {

		bool ok = false;

		char postalCode[30] = {'\0'};
	
		if (read(postalCode)) {

			if (read(postalCodePop.Population)) {

				postalCodePop.PostalCode = new char[strLen(postalCode) + 1];
				strCpy(postalCodePop.PostalCode, postalCode);
				popTotal += postalCodePop.Population;
				ok = true;
			}
		} return ok;
	}


	bool load(const char filename[]) {
		bool ok = false;

		if (openFile(filename)) {

			postalCodeNo = noOfRecords();
			postalcodePOP = new PopPC[postalCodeNo];

			for (int i = 0; i < postalCodeNo; i++) {

				if (!load(postalcodePOP[i])) {

					cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
					closeFile();
					return false;
				}
			}
			closeFile();
			ok = true;

		}
		else {
			cout << "Could not open data file: " << filename << endl;
		} return ok;
	}


	void sort() {
		PopPC temp;

		for (int i = postalCodeNo - 1; i > 0; i--) {

			for (int x = 0; x < i; x++) {

				if (postalcodePOP[x].Population > postalcodePOP[x + 1].Population) {

					temp = postalcodePOP[x];

					postalcodePOP[x] = postalcodePOP[x + 1];

					postalcodePOP[x + 1] = temp;
				}
			}
		}
	}

	
	void display() {
	cout << "Postal Code: population" << endl;
	cout << "-------------------------" << endl;

	sort();

	for (int number = 0; number < postalCodeNo; number++) {
		
		cout << number + 1 << "- ";
		display(postalcodePOP[number]);

		}	

		cout << "-------------------------" << endl;
		cout << "Population of Canada: " << popTotal <<endl; 
	}
	
	
	void display(const PopPC& postalcodePOP) {
		cout << postalcodePOP.PostalCode << ":  " << postalcodePOP.Population << endl;
	}


}
