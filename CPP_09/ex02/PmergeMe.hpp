/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/02/10 20:19:36 by ancolmen         ###   ########.fr       */
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

class PmergeMe {
	
	public:
		PmergeMe();
		~PmergeMe();

		//methods

		//get set

		class PmergeMeError : public std::exception {
			
			public:
				PmergeMeError(std::string errorMsg) throw();
				~PmergeMeError() throw();

				virtual const char *what() const throw();

			private:
				std::string _errorMsg;

		};

	private:
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &other);
		
		//vars

};

#endif
