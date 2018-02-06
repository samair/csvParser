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
   
   void parse();

   stringVector parseRow(std::string, size_t commaPos=0);
   
   stringVector _columnNames;

   
   public:
   //take input csvFile
   csvParse(std::string fileName);

   //parse columns
   std::string columns();

};
#endif //_CSV_PARSE_
