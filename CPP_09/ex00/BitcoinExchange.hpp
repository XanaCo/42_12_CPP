/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/02/12 19:03:07 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <istream>
# include <fstream>
# include <sstream>
# include <iterator>
# include <unistd.h>
# include <cstdlib>
# include <exception>
# include <algorithm>
# include <sys/stat.h>
# include <cfloat>

# include <map>

# define RED "\033[31;1m"
# define GREEN "\033[32;1m"
# define YELLOW "\033[33;1m"
# define WHITE "\033[37;1m"
# define END_COLOR "\033[0m"

# define VALID 1
# define NOT_VALID 0

# define DB_PATHFILE "data.csv"
# define DB_FORMAT ".csv"
# define IN_FORMAT ".txt"
# define IN_SEPARATOR " | "
# define DB_SEPARATOR ","
# define IN_HEADER "date | value"
# define DB_HEADER "date,exchange_rate"

enum fileType {
	INPUT,
	DB
};

class DataBase {
	
	public:
		DataBase(std::string filePath);
		~DataBase();

		void checkFileValid(std::string filePath, std::string format);
		void openLoadRead(std::string filePath, std::string const format);
		bool checkHeaderFormat(std::string const &line, std::string header);
		bool checkLineFormat(std::string date, std::string num, fileType file);	
		bool checkInputNum(float const &number, fileType file);
		bool checkInputDate(std::string const &date);
		bool loadDataBase(std::string line);
		bool readInput(std::string line);

		void setData(std::string const &date, float const &number);
		std::string getError();
		std::map<std::string, float> getData();

		class DataError : public std::exception {
			
			public:
				DataError(std::string errorMsg) throw();
				~DataError() throw();

				virtual const char *what() const throw();

			private:
				std::string _errorMsg;

		};

	private:
		DataBase();
		DataBase(DataBase const &copy);
		DataBase &operator=(DataBase const &other);
		
		std::map<std::string, float> _data;
		std::string _errorPrint;

};

#endif
