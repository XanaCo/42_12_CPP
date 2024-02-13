/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/02/13 19:09:35 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <exception>
# include <algorithm>
# include <typeinfo>
# include <ctime>

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
		double sort(Container container) {
			
			clock_t time = clock();
	
			if (typeid(Container) == typeid(std::vector<int>))
				fordJohnsonVector(_array, 0, _size - 1);
				
			else if (typeid(Container) == typeid(std::list<int>))
				fordJohnsonList(_list);

			time = clock() - time;
			
			(void)container;
			return time * 1000000 / CLOCKS_PER_SEC;
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
		
		void fordJohnsonVector(std::vector<int> &array, int left, int right);
		void fordJohnsonList(std::list<int> &list);

		void mergeVector(std::vector<int> &array, int left, int mid, int right);
		void mergeList(std::list<int> &list, std::list<int> &left, std::list<int> &right);
		
		std::vector<int>	_array;
		std::list<int>		_list;
		int					_size;

};

template <typename Container>
void printContainer(Container container) {
	
	typename Container::iterator it = container.begin();
	typename Container::iterator ite = container.end();

	while (it != ite)
	{
		std::cout << *it;
		if (++it != ite)
			std::cout << " ";
	}
	std::cout << std::endl;
}

#endif
