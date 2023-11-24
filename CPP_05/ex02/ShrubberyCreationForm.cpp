/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/24 17:48:56 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*::: CONSTRUCTORS :::*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {

	return ;
}

/*::: DESTRUCTORS :::*/

ShrubberyCreationForm::~ShrubberyCreationForm() {

	std::cout << RED
			<< "Destructor: "
			<< this->getName()
			<< " destroyed"
			<< END_COLOR << std::endl;

	return ;
}

/*::: MEMBER FUNCTIONS :::*/

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {

	(void)executor;
	std::cout << "on execute Shrubbery" << std::endl;
}
