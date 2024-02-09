/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/02/09 19:21:17 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// ************************************************************************** //
//	CONSTRUCTOR / DESTRUCTOR
// ************************************************************************** //

DataBase::DataBase(std::string filePath, std::string format) : _filePath(filePath), _format(format), _error("") {

	if (_format == IN_FORMAT)
	{
		_header = "date | value";
		_separator = " | ";
	}
	else if (_format == DB_FORMAT)
	{
		_header = "date,exchange_rate";
		_separator = ",";
	}
}

DataBase::~DataBase() {}


// ************************************************************************** //
//	LA GET-SET
// ************************************************************************** //


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

void DataBase::openStock() {

	std::ifstream fileStream;
	std::string line;

	fileStream.open(_filePath.c_str());
	if (fileStream.fail())
		throw DataError("Error: could not open file.");
	
	std::getline(fileStream, line);
	if (checkHeaderFormat(line) == NOT_VALID)
	{
		fileStream.close();
		throw DataError("Error: bad input => date | value.");
	}

	while (std::getline(fileStream, line)) // while there is something in file, go on
	{
		if (checkLineFormat(line) == NOT_VALID)
		{
			fileStream.close();
			throw DataError(_error);
		}
	
		//transform number in float with atof
		//stock date + value in map
		
	}
	fileStream.close();

}


// if all OK
	// std::cout << input.first << " => " << input.second << " = " << (input.second * data.second) << std::endl;


// ************************************************************************** //
//	METHODS
// ************************************************************************** //

bool DataBase::checkHeaderFormat(std::string const &line) {
	
	if (!line.compare(_header))
		return VALID;
	
	return NOT_VALID;
		
}

bool DataBase::checkLineFormat(std::string const &line) {

	std::string date = line.substr(0, line.find(_separator));
	std::string num = line.substr(line.find(_separator) + 1);
		
	if (checkDate(date) == NOT_VALID)
	{
		_error = "Error: bad input => " + date;
		return NOT_VALID;
	}

	if (checkNum(num) == NOT_VALID)
	{
		_error = "Error: bad input => " + num;
		return NOT_VALID;
	}

}

bool DataBase::checkDate(std::string const &date) {
	
	//date does not exist: check closest lower date
}


bool DataBase::checkNum(std::string const &num) {

	//extract num
		// 0 - 1000 (float or unsigned int)?
			//std::cerr << "Error: too large a number." << std::endl;
			//std::cerr << "Error: not a positive number." << std::endl;
		//transform number in float with atof
		//stock date + value in map
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

		data.openStock();
		input.openStock();

		//multiply!
}
