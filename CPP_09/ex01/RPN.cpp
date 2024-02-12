/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/02/12 16:10:01 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// ************************************************************************** //
//	CONSTRUCTOR / DESTRUCTOR
// ************************************************************************** //

RPNCalculator::RPNCalculator() {}

RPNCalculator::~RPNCalculator() {}

// ************************************************************************** //
//	LA GET-SET
// ************************************************************************** //

std::stack<double> RPNCalculator::getStack() {

	return this->_stack;
}

// ************************************************************************** //
//	METHODS
// ************************************************************************** //

void RPNCalculator::calculateRPN(std::string const &expression) {
	
	std::istringstream iss(expression);
	std::string element;

	while (iss >> element)
	{
		if (isOperand(element) == YES)
			_stack.push(std::strtol(element.c_str(), NULL, 10));

		else if (isOperator(element) == YES)
			doTheMath(element.at(0));

		else
			throw RPNerror("Error: wrong input in expression");
	}

	if (_stack.size() != 1)
		throw RPNerror("Error: extra numbers in input");

	std::cout << GREEN << _stack.top() << END_COLOR << std::endl;
}

bool RPNCalculator::isOperand(std::string element) {

	std::string operands = OPERAND;

	if (element.size() != 1 || operands.find(element.at(0)) == std::string::npos)
		return NO;

	return YES;
}

bool RPNCalculator::isOperator(std::string element) {

	std::string operators = OPERATOR;

	if (element.size() != 1 || operators.find(element.at(0)) == std::string::npos)
		return NO;

	return YES;
}

void RPNCalculator::doTheMath(char elementOperator) {

	double result;
	double op1;
	double op2;

	if (_stack.size() < 2)
		throw RPNerror("Error: not enough operands");

	op2 = _stack.top();
	_stack.pop();
	op1 = _stack.top();
	_stack.pop();

	switch (elementOperator)
	{
		case '+':
			result = op1 + op2;
			break;
		case '-':
			result = op1 - op2;
			break;
		case '/':
		{
			if (op2 == 0)
				throw RPNerror("Error: division by zero not allowed");
			result = op1 / op2;
			break;
		}
		case '*':
			result = op1 * op2;
			break;
		default:
			throw RPNerror("Error: something went wrong in the operation");
			return;
	}

	_stack.push(result);	
}

// ************************************************************************** //
//	EXCEPTIONS
// ************************************************************************** //

RPNCalculator::RPNerror::RPNerror(std::string errorMsg) throw() : _errorMsg(errorMsg) {}
				
RPNCalculator::RPNerror::~RPNerror() throw() {}

const char *RPNCalculator::RPNerror::what() const throw() {

	return _errorMsg.c_str();
}
