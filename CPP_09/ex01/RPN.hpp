/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/02/10 20:19:36 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <exception>
# include <algorithm>
# include <stack>

# define RED "\033[31;1m"
# define GREEN "\033[32;1m"
# define YELLOW "\033[33;1m"
# define WHITE "\033[37;1m"
# define END_COLOR "\033[0m"

# define YES 1
# define NO 0

# define OPERATOR "+-/*"
# define OPERAND "0123456789"

class RPNCalculator {
	
	public:
		RPNCalculator();
		~RPNCalculator();

		void calculateRPN(std::string const &expression);
		bool isOperand(std::string element);
		bool isOperator(std::string element);
		void doTheMath(char elementOperator);

		std::stack<double> getStack();

		class RPNerror : public std::exception {
			
			public:
				RPNerror(std::string errorMsg) throw();
				~RPNerror() throw();

				virtual const char *what() const throw();

			private:
				std::string _errorMsg;

		};

	private:
		RPNCalculator(RPNCalculator const &copy);
		RPNCalculator &operator=(RPNCalculator const &other);
		
		std::stack<double> _stack;

};

#endif
