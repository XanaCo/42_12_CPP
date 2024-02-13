/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/02/13 15:11:15 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <exception>
# include <algorithm>
# include <typeinfo>

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

		int getSize() const;
		std::vector<int> getArray() const;
		std::list<int> getList() const;

		template<typename Container>
		void sort(Container container) {
			
			if (getType(container) == LIST)
				std::cout << "List sorting func " << std::endl;
				
			if (getType(container) == VECTOR)
				std::cout << "Vector sorting func " << std::endl;
		}

		template<typename Container>
		void time(Container container) {

			std::string cont;
			
			if (getType(container) == LIST)
				cont = LIST;
				
			if (getType(container) == VECTOR)
				cont = VECTOR;
				
			std::cout << "Time to process a range of "
				<< _size << " elements with " << cont << " : " << std::endl;
		}

		template<typename Container>
		std::string getType(Container const &container) {
	
			(void)container;
			
			if (typeid(Container) == typeid(std::vector<int>))
				return VECTOR;
				
			if (typeid(Container) == typeid(std::list<int>))
				return LIST;
				
			return "Unknown";
		}

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
		int					_timeArray;
		std::list<int>		_list;
		int					_timeList;
		int					_size;

};

template <typename T>
void printContainer(T container) {
	
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();

	while (it != ite)
	{
		std::cout << *it;
		if (++it != ite)
			std::cout << " ";
	}
	std::cout << std::endl;
}

#endif
