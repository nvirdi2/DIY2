/// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: Jan 31, 2021

//I have done all the coding by myself with the help of the LAB  

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
//#define DATAFILE "PCpopulations.csv"

namespace sdds 
{
    struct PopPC {
            char* PostalCode;
            int Population;
        };

    void sort();

	bool load(const char filename[]);
    bool load(PopPC& postalcodePOP);

	void display();
    void display(const PopPC& postalcodePOP);

	void deallocateMemory();

}
#endif // SDDS_POPULATION_H_
