/// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: Jan 31, 2021

//I have done all the coding by myself with the help of the LAB 

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();

   bool read(char* postalCode);
   bool read(int &Population); 
}
#endif // !SDDS_FILE_H_
