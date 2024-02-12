/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/02/12 16:14:39 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// ************************************************************************** //
//	CONSTRUCTOR / DESTRUCTOR
// ************************************************************************** //

DataBase::DataBase(std::string filePath) {

	checkFileValid(DB_PATHFILE, DB_FORMAT);
	checkFileValid(filePath, IN_FORMAT);
	openLoadRead(DB_PATHFILE, DB_HEADER);
}

DataBase::~DataBase() {}

// ************************************************************************** //
//	LA GET-SET
// ************************************************************************** //

void DataBase::setData(std::string const &date, float const &number) {
	
	this->_data[date] = number;
}

std::string DataBase::getError() {

	return this->_errorPrint;
}

std::map<std::string, float> DataBase::getData() {

	return this->_data;
}

// ************************************************************************** //
//	METHODS
// ************************************************************************** //

void DataBase::checkFileValid(std::string filePath, std::string format)
{
	struct stat fileStat;

	if (filePath.empty() || !filePath.length())
		throw DataError("Error: could not access " + filePath);

	if (stat(filePath.c_str(), &fileStat) == -1)
		throw DataError("Error: permission denied or bad address in " + filePath);

	if (!(fileStat.st_mode & S_IFREG))
		throw DataError("Error: invalid " + filePath + " file");

	if (access(filePath.c_str(), R_OK) == -1)
		throw DataError("Error: could not read " + filePath + " file");

	if (filePath.find(format, filePath.size() - 4) == std::string::npos)
		throw DataError("Error: wrong file format (" + format + ")");
}

bool DataBase::checkHeaderFormat(std::string const &line, std::string header) {

	if (!line.compare(header))
		return VALID;

	return NOT_VALID;
}

bool DataBase::checkLineFormat(std::string date, std::string num, fileType file) {

	bool dot = false;
	bool sign = false;

	if (checkInputDate(date) == NOT_VALID)
		return NOT_VALID;

	for (size_t i = 0; i < num.size(); i++)
	{
		if (num[i] == '.')
		{
			if (dot == true)
			{
				_errorPrint = "Error: bad float input => " + num;
				return NOT_VALID;
			}
			dot = true;
		}
		else if (num[i] == '-')
		{
			if (sign == true)
			{
				_errorPrint = "Error: bad sign input => " + num;
				return NOT_VALID;
			}
			sign = true;
		} 
		else if (!std::isdigit(num[i]))
		{
			_errorPrint = "Error: not a number => " + num;
			return NOT_VALID;
		}
	}
	float number = atof(num.c_str());
	
	if (file == DB && checkInputNum(number, DB) == NOT_VALID)
		return NOT_VALID;

	if (file == INPUT && checkInputNum(number, INPUT) == NOT_VALID)
		return NOT_VALID;

	return VALID;
}

bool DataBase::checkInputDate(std::string const &date) {
	
	if (date.length() != 10)
	{
		_errorPrint = "Error: bad input => " + date;
		return NOT_VALID;
	}

	for (size_t i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
			{
				_errorPrint = "Error: bad input => " + date;
				return NOT_VALID;
			}
		} 
		else if (!std::isdigit(date[i]))
		{
			_errorPrint = "Error: bad input => " + date;
			return NOT_VALID;
		}
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	if (year < 2009 || year > 2023)
	{
		_errorPrint = "Error: bad year => " + date;
		return NOT_VALID;
	}

	int month = std::atoi(date.substr(5, 2).c_str());
	if (month < 1 || month > 12)
	{
		_errorPrint = "Error: bad month => " + date;
		return NOT_VALID;
	}

	int day = std::atoi(date.substr(8, 2).c_str());
	if (day < 1)
	{
		_errorPrint = "Error: day must be positive => " + date;
		return NOT_VALID;
	}

	if (month == 2 && day > 29)
	{
		_errorPrint = "Error: february is a shorter month => " + date;
		return NOT_VALID;
	}

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		_errorPrint = "Error: this month has 30 days => " + date;
		return NOT_VALID;
	}

	if (day > 31)
	{
		_errorPrint = "Error: this month has 31 days => " + date;
		return NOT_VALID;
	}
	
	return VALID;
}


bool DataBase::checkInputNum(float const &number, fileType file) {

	if (file == INPUT)
	{
		if (number > 1000)
		{
			_errorPrint = "Error: too large a number";
			return NOT_VALID;
		}

		else if (number < 0)
		{
			_errorPrint = "Error: not a positive number";
			return NOT_VALID;
		}
	}

	if (file == DB)
	{
		if (number < 0 || number > FLT_MAX)
		{
			_errorPrint = "Error: wrong range of prices in data.csv";
			return NOT_VALID;
		}
	}
	
	return VALID;
}

void DataBase::openLoadRead(std::string filePath, std::string header) {

	std::ifstream fileStream;
	std::string line;

	fileStream.open(filePath.c_str());
	if (fileStream.fail())
		throw DataError("Error: could not open file");
	
	std::getline(fileStream, line);
	if (checkHeaderFormat(line, header) == NOT_VALID)
	{
		fileStream.close();
		throw DataError("Error: bad header format");
	}

	while (std::getline(fileStream, line))
	{
		if (line.empty())
			continue ;

		if (header == DB_HEADER)
		{
			if (loadDataBase(line) == NOT_VALID)
			{
				fileStream.close();
				throw DataError(_errorPrint);
			}
		}
		else if (header == IN_HEADER)
		{
			if (readInput(line) == NOT_VALID)
				std::cerr << YELLOW << _errorPrint << END_COLOR << std::endl;
		}
	}
	fileStream.close();
}

bool DataBase::loadDataBase(std::string line) {

	std::string date = line.substr(0, line.find(DB_SEPARATOR));
	std::string num = (line.substr(line.find(DB_SEPARATOR) + 1));

	if (checkLineFormat(date, num, DB) == NOT_VALID)
		return NOT_VALID;

	float number = atof(num.c_str());
	setData(date, number);

	return VALID;
}

bool DataBase::readInput(std::string line) {
	
	std::string date = line.substr(0, line.find(IN_SEPARATOR));
	std::string num = (line.substr(line.find(IN_SEPARATOR) + 3));

	if (checkLineFormat(date, num, INPUT) == NOT_VALID)
		return NOT_VALID;
			
	float number = atof(num.c_str());
	std::map<std::string, float>::iterator it = _data.find(date);

	std::string last_date;
    float last_value;

 	for (it = _data.begin(); it != _data.end(); it++)
	{
		if (it->first > date)
			break ;
		last_date = it->first;
		last_value = it->second;
	}

	std::cout << GREEN << date << " => " << num << " = " << last_value * number << END_COLOR << std::endl;
	return VALID;
}

// ************************************************************************** //
//	EXCEPTIONS
// ************************************************************************** //

DataBase::DataError::DataError(std::string errorMsg) throw() : _errorMsg(errorMsg) {}
				
DataBase::DataError::~DataError() throw() {}

const char *DataBase::DataError::what() const throw() {

	return _errorMsg.c_str();
}
