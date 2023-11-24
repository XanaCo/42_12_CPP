/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/24 14:13:11 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

# define WHITE "\033[97;1m"
# define YELLOW "\033[33;1m"
# define BLUE "\033[34;1m"
# define MAGENTA "\033[95;1m"
# define RED "\033[31m"
# define GREEN "\033[32m"
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
