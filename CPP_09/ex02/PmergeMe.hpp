/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/02/12 19:25:04 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <exception>
# include <algorithm>

# include <vector>
# include <list>

# define RED "\033[31;1m"
# define GREEN "\033[32;1m"
# define YELLOW "\033[33;1m"
# define WHITE "\033[37;1m"
# define END_COLOR "\033[0m"

# define YES 1
# define NO 0

# define DIGIT "0123456789"
# define LIST "std::list<int>"
# define VECTOR "std::vector<int>"

class PmergeMe {
	
	public:
		PmergeMe(int size, char **listNum);
		~PmergeMe();

		template<typename T>
		void sort(T container);

		template<typename T>
		void time(T container) {

			std::cout << "Time to process a range of " << _size << " elements with " << container.getType() <<" : ";
			//getType, getTime

		}

		std::vector<int> getArray() const;
		std::list<int> getList() const;
		std::string getType();

		class PmergeMeError : public std::exception {
			
			public:
				PmergeMeError(std::string errorMsg) throw();
				~PmergeMeError() throw();

				virtual const char *what() const throw();

			private:
				std::string _errorMsg;

		};

	private:
		PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &other);
		
		std::vector<int>	_array;
		std::list<int>		_list;
		int					_size;
		int					_timeArray;
		int					_timeList;

};

template<typename T>
void	printVector(T container);

#endif
