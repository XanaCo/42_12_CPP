/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/12/21 17:28:53 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

# define B_RED "\033[91;1m"
# define B_GREEN "\033[92;1m"
# define B_YELLOW "\033[93;1m"
# define B_BLUE "\033[94;1m"
# define B_MAGENTA "\033[95;1m"
# define B_CYAN "\033[96;1m"
# define B_WHITE "\033[97;1m"

# define RED "\033[31;1m"
# define GREEN "\033[32;1m"
# define YELLOW "\033[33;1m"
# define BLUE "\033[34;1m"
# define MAGENTA "\033[35;1m"
# define CYAN "\033[36;1m"
# define WHITE "\033[37;1m"

# define END_COLOR "\033[0m"

# define MAX_GRADE 1
# define MIN_GRADE 150

class Bureaucrat {

public:
	Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &copy);
	~Bureaucrat();

	Bureaucrat	&operator=(Bureaucrat const &other);

	std::string const	&getName() const;
	int const			&getGrade() const;

	void				bureaucratPromotion();
	void				bureaucratDemotion();

	class GradeTooHighException : public std::exception {
	
		public:
			const char *what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
		
		public:
			const char *what() const throw();
	};

	class NoName : public std::exception {
		
		public:
			const char *what() const throw();
	};

private:
	std::string	const	_name;
	int					_grade;

};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
