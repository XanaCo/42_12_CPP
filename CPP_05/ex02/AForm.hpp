/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/24 17:25:20 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

public:
	AForm();
	AForm(std::string const name, int gradeSign, int gradeExec);
	AForm(AForm const &copy);
	virtual ~AForm();

	std::string const &getName() const;
	bool getIsSigned() const;
	int const &getGradeSign() const;
	int const &getGradeExec() const;	
	void beSigned(Bureaucrat const &someone);

	virtual void execute(Bureaucrat const &executor) const = 0;

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
	AForm	&operator=(AForm const &other);

	std::string	const	_name;
	bool				_signed;
	int const			_gradeSign;
	int const			_gradeExec;

};

std::ostream &operator<<(std::ostream &out, AForm const &AForm);

#endif
