/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/02/10 20:46:24 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// ************************************************************************** //
//	CONSTRUCTOR / DESTRUCTOR
// ************************************************************************** //

DataBase::DataBase(std::string filePath, std::string format) : _filePath(filePath), _format(format), _errorPrint("") {

	if (_format == IN_FORMAT)
	{
		_header = "date | value";
		_separator = " | ";
	}
	else if (_format == DB_FORMAT)
	{
		_header = "date,exchange_rate";
		_separator = ",";
		// openLoadRead();
	}
}

DataBase::~DataBase() {}


// ************************************************************************** //
//	LA GET-SET
// ************************************************************************** //

void DataBase::setData(std::string const &date, float const &number) {
	
	this->_data[date] = number;
}

std::string DataBase::getFilePath() const {

	return this->_filePath;
}

std::string DataBase::getFormat()const {

	return this->_format;
}

std::string DataBase::getHeader() {

	return this->_header;
}

std::string DataBase::getError() {

	return this->_errorPrint;
}

std::string DataBase::getSeparator() {

	return this->_separator;
}

std::map<std::string, float> DataBase::getData() {

	return this->_data;
}

// ************************************************************************** //
//	METHODS
// ************************************************************************** //

void DataBase::checkFileValid()
{
	struct stat fileStat;

	if (_filePath.empty() || !_filePath.length())
		throw DataError("Error: could not access file.");

	if (stat(_filePath.c_str(), &fileStat) == -1)
		throw DataError("Error: permission denied or bad address.");

	if (!(fileStat.st_mode & S_IFREG))
		throw DataError("Error: invalid file.");

	if (access(_filePath.c_str(), R_OK) == -1)
		throw DataError("Error: could not read file.");

	if (_filePath.find(_format, _filePath.size() - 4) == std::string::npos)
		throw DataError("Error: wrong file format.");
}

void DataBase::openLoadRead() {

	std::ifstream fileStream;
	std::string line;

	fileStream.open(_filePath.c_str());
	if (fileStream.fail())
		throw DataError("Error: could not open file.");
	
	std::getline(fileStream, line);
	if (checkHeaderFormat(line) == NOT_VALID)
	{
		fileStream.close();
		throw DataError("Error: bad header format.");
	}

	while (std::getline(fileStream, line))
	{
		if (_format == DB_FORMAT)
			loadDataBase(line);

		if (_format == IN_FORMAT)
			readInput(line);
	}

	fileStream.close();

}

void DataBase::loadDataBase(std::string line) {

	if (checkLineFormat(line) == NOT_VALID)
	{
		// fileStream.close();???
		throw DataError(_errorPrint);
	}
			
	std::string date = line.substr(0, line.find(_separator));
	std::string num = (line.substr(line.find(_separator) + 1));
	float number = atof(num.c_str());

	setData(date, number);
}

void DataBase::readInput(std::string line) {
	
	if (checkLineFormat(line) == NOT_VALID)
	{
		std::cerr << _errorPrint << std::endl;
		return ;
	}
			
	std::string date = line.substr(0, line.find(_separator));
	std::string num = (line.substr(line.find(_separator) + 1));
	float number = atof(num.c_str());

	
}


bool DataBase::checkHeaderFormat(std::string const &line) {
	
	if (!line.compare(_header))
		return VALID;
	
	return NOT_VALID;
		
}

bool DataBase::checkLineFormat(std::string const &line) {

	std::string date = line.substr(0, line.find(_separator));
	std::string num = line.substr(line.find(_separator) + 1);
	float number = atof(num.c_str());
	
	if (_format == DB_FORMAT)
	{
		//check .csv format
		_errorPrint = "An error message here from DB line format";
		
	}
	if (_format  == IN_FORMAT)
	{
		if (checkInputDate(date) == NOT_VALID || checkInputNum(number) == NOT_VALID)
		{
			return NOT_VALID;
		}
	}
		
}

bool DataBase::checkInputDate(std::string const &date) {
	
	std::cout << "my date in checkinputdate = " << date << std::endl;
	//date does not exist: check closest lower date
}


bool DataBase::checkInputNum(float const &number) {

	std::cout << "my num in checkinputnum = " << number << std::endl;

	if (number > 1000)
		_errorPrint = "Error: too large a number.";

	else if (number < 0)
		_errorPrint = "Error: not a positive number.";
	
}

// ************************************************************************** //
//	EXCEPTIONS
// ************************************************************************** //

DataBase::DataError::DataError(std::string errorMsg) throw() : _errorMsg(errorMsg) {}
				
DataBase::DataError::~DataError() throw() {}

const char *DataBase::DataError::what() const throw() {

	return _errorMsg.c_str();
}

// ************************************************************************** //
//	OTHER FUNCTIONS
// ************************************************************************** //

void doTheMath(DataBase &input, DataBase &data) {

		data.checkFileValid();
		input.checkFileValid();

		input.readPrint();

		// if all OK
	// std::cout << input.first << " => " << input.second << " = " << (input.second * data.second) << std::endl;
}
