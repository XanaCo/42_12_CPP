/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/17 23:00:22 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form {

public:
	Form(void);
	Form(std::string const name, int gradeSign, int gradeExec);
	Form(Form const &copy);
	~Form(void);

	Form	&operator=(Form const &other);

	std::string const getName(void) const;
	bool isSigned(void) const;
	int getGradeSign(void) const;
	int getGradeExec(void) const;
	void beSigned(Bureaucrat someone);
	void signForm(void);

	class GradeTooHighException : public std::exception {
	
		public:
			const char *what(void) const throw();
	};
	
	class GradeTooLowException : public std::exception {
		
		public:
			const char *what(void) const throw();
	};

	class NoName : public std::exception {
		
		public:
			const char *what(void) const throw();
	};

private:
	std::string	const	_name;
	bool				_signed;
	int const			_gradeSign;
	int const			_gradeExec;

};

std::ostream &operator<<(std::ostream &out, Form const &Form);

#endif
