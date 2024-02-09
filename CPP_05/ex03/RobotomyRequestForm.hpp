/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/12/20 21:52:47 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <fstream>

class RobotomyRequestForm : public AForm {

	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();

		RobotomyRequestForm(RobotomyRequestForm const &copy);

		std::string const &getTarget() const;
		void execute(Bureaucrat const &executor) const;

		class RobotomyException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	
	private:
		RobotomyRequestForm();
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &other);
	
		std::string _target;
		static int _robotomizations;

};

#endif
