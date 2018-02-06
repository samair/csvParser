#include "csv_parse.h"

char comma_str =',';

// the idea is to parse the csv file during the creation of object.
// get basic info once parsed such as name of the columns,
// number of rows/colums etc.

csvParse::csvParse(std::string csvFileName):
                 _fileName(csvFileName)
{
  //kick parsing 
  parse();
}

void csvParse::parse()
{
  //first step os to open the file 
  _file.open(_fileName.c_str(),std::ifstream::in);
  if(!_file)
  {
   std::cout<<"Error no such file exists"<<std::endl;
  }
  //now read line by line
  std::string line;
  while(std::getline(_file,line))
  {
   
   //first row of the file separated by comma's are column names
   _columnNames = parseRow(line);
   stringVector::iterator strVectItr;
   for(strVectItr = _columnNames.begin(); strVectItr!=_columnNames.end(); ++strVectItr)
    {
      std::cout<<" " <<*strVectItr<<" " ;
    }
     std::cout<<std::endl;
   break;
  }
  _file.close();
   
}

stringVector csvParse::parseRow(std::string line, size_t commaPos)
{

   stringVector vectOftheRow;
  //read a line, find for comma's and push into vector
  size_t firstComma = line.find_first_of(comma_str);
  //if there is no comma, then probably there only one column
  vectOftheRow.push_back(line.substr(0,firstComma-1));
  while (firstComma != std::string::npos)
  {
    size_t posStart =firstComma;
    firstComma = line.find_first_of(comma_str,firstComma+1);
    vectOftheRow.push_back(line.substr(posStart+1,(firstComma-posStart)-1));
  }
  return vectOftheRow;
}
