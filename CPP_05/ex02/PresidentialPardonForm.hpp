/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/12/20 22:06:04 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm {

	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();

		PresidentialPardonForm(PresidentialPardonForm const &copy);

		std::string const &getTarget() const;
		void execute(Bureaucrat const &executor) const;

		class RobotomyException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	
	private:
		PresidentialPardonForm();
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &other);
	
		std::string _target;

};

#endif
