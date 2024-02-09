/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/02/09 19:01:30 by ancolmen         ###   ########.fr       */
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
# include <map>
# include <sys/stat.h>


# define RED "\033[31;1m"
# define GREEN "\033[32;1m"
# define YELLOW "\033[33;1m"
# define WHITE "\033[37;1m"
# define END_COLOR "\033[0m"

# define VALID 1
# define NOT_VALID 0

# define DB_FILE "data.csv"
# define IN_FORMAT ".txt"
# define DB_FORMAT ".csv"

class DataBase {
	
	public:
		DataBase(std::string filePath, std::string format);
		~DataBase();

		void checkFileValid();
		bool checkHeaderFormat(std::string const &line);
		bool checkLineFormat(std::string const &line);
		bool checkDate(std::string const &date);
		bool checkNum(std::string const &date);

		void openStock();

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
		
		std::string const _filePath;
		std::string const _format;
		std::string _header;
		std::string _error;
		std::string _separator;
		std::map<std::string, float> _data;

};

void doTheMath(DataBase &input, DataBase &data);


#endif
