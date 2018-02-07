#ifndef _CSV_PARSE_
#define _CSV_PARSE_

#include <iostream>
#include <fstream>
#include <vector>
typedef  std::vector<std::string> stringVector;


class csvParse{

   private:
   // Name of the file to be parsed
   std::string _fileName;  
   //Internal file stream
   std::ifstream _file;

   //Number of rows in the csv file
   unsigned int _numRows;
   
   void parse();

   stringVector parseRow(std::string, size_t commaPos=0);
   
   stringVector _columnNames;

   
   public:
   //take input csvFile
   csvParse(std::string fileName);

   //parse columns
   inline stringVector getColumns()
   {return _columnNames;} 

   //get number of rows in the csv file
   inline unsigned int getNumRows()
   { return _numRows;}

};
#endif //_CSV_PARSE_
