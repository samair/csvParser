#include<iostream>
#include "csv_parse.h"


int main()
{ 
   csvParse _csvFile("test.csv");   
   unsigned int numRow = _csvFile.getNumRows();   
   std::cout<<"Number of rows in the scv file:: "<<numRow<<std::endl;

   stringVector strVec = _csvFile.getColumns();
    std::cout<<"_ _ _Columns_ _ _ "<<std::endl;
   for (stringVector::iterator strItr = strVec.begin(); strItr!=strVec.end(); ++strItr)
     {
        std::cout<<*strItr<<std::endl;
     }
   stringVector strColumsn = _csvFile["Name"];

}
