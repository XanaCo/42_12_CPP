/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/24 16:51:30 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:
	Form();
	Form(std::string const name, int gradeSign, int gradeExec);
	Form(Form const &copy);
	~Form();

	std::string const &getName() const;
	bool getIsSigned() const;
	int const &getGradeSign() const;
	int const &getGradeExec() const;	
	void beSigned(Bureaucrat const &someone);

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
	Form	&operator=(Form const &other);

	std::string	const	_name;
	bool				_signed;
	int const			_gradeSign;
	int const			_gradeExec;

};

std::ostream &operator<<(std::ostream &out, Form const &Form);

#endif
