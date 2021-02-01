/// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: Jan 31, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#define DATAFILE "PCpopulations.csv"

namespace sdds 
{
    struct PopulationPC {
            char* PostalCode;
            int Population;
        };

    void sort();
	bool load(PopulationPC& postalcodePOP);
	bool load();
	void display(const PopulationPC& postalcodePOP);
	void display();


	void deallocateMemory();

}
#endif // SDDS_POPULATION_H_
