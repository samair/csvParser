#include "csv_parse.h"

char comma_str =',';

// the idea is to parse the csv file during the creation of object.
// get basic info once parsed such as name of the columns,
// number of rows/colums etc.

csvParse::csvParse(std::string csvFileName):
                 _fileName(csvFileName),_numRows(0)
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
	bool isFirstColumn = false;
	while(std::getline(_file,line))
	{
		//first row of the file separated by comma's are column names
		if (!isFirstColumn)
		{
			_columnNames = parseRow(line);
			isFirstColumn = true;
		}
		++_numRows ;
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
      //trim the strip before using it ( remove leading and trailing spaces.)
      //std::string str(line.substr(posStart+1,(firstComma-posStart)-1);
     // trim (str);
		vectOftheRow.push_back(line.substr(posStart+1,(firstComma-posStart)-1));
	}
	return vectOftheRow;
}

stringVector csvParse::operator[](const std::string& columnName)
{
	stringVector columnVals;
	// we have the column name
	// first check if we have such a column name or not 
	stringVector::iterator strItr;
	unsigned int countColumn =0;
	for (strItr = _columnNames.begin(); strItr != _columnNames.end(); ++strItr)
	{
		++countColumn;
		std::string str(*strItr); 
		size_t strFound = str.find(columnName);
		if (strFound != std::string::npos)
		{
			parseColumn(columnVals,countColumn-1);
         break;
		}   
		// calculate number now.
	}

	return columnVals;
}

void  csvParse::parseColumn(stringVector& columnVals, unsigned int columnNum)
{
	_file.open(_fileName.c_str(),std::ifstream::in);
	if(!_file)
	{
		std::cout<<"Error no such file exists"<<std::endl;
	}
	//now read line by line
	std::string line;
	bool isFirstColumn = false;
	while(std::getline(_file,line))
	{
		//first row of the file separated by comma's are column names
		if (!isFirstColumn)
		{
			isFirstColumn = true;
			continue;
		}
		size_t firstComma = line.find_first_of(comma_str);
		unsigned int commaCount = 0;
		//if there is no comma, then probably there only one column
		//if ( firstComma == std::string::npos &&  0 == columnNum)
		//	columnVals.push_back(line);

		while (firstComma != std::string::npos)
		{
			size_t posStart =firstComma;
         ++commaCount;
			firstComma = line.find_first_of(comma_str,firstComma+1);
         if (firstComma == std::string::npos && (commaCount+1 == columnNum))
         {
            columnVals.push_back(line.substr(posStart+1,std::string::npos));
		    	std::cout<<"Columns are:"<<line.substr(posStart+1,std::string::npos)<<std::endl;
         }
          
         else if ( commaCount == columnNum)
         {
			columnVals.push_back(line.substr(posStart+1,(firstComma-posStart)-1));
			std::cout<<"Columns are:"<<line.substr(posStart+1,(firstComma-posStart)-1)<<std::endl;
         }
		}
	}
	_file.close();

}
