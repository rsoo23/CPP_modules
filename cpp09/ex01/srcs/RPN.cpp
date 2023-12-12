/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:16:28 by rsoo              #+#    #+#             */
/*   Updated: 2023/12/12 15:02:40 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.h"

RPN::RPN() {
	_op = "+-/*";
}

RPN::RPN( const RPN& other ) {
	(void)other;
}

RPN& RPN::operator=( const RPN& other ) {
	(void)other;
	return *this;
}

RPN::~RPN() {}

void RPN::calculate( const std::string& expr ) {
	try {
		int i = 0;

		checkExpressionFormat(expr);

		while (expr[i])
		{
			if (expr[i] == ' ')
				i++;
			// while there is a digit, push them to the stack
			while (expr[i] && isdigit(expr[i])) {
				_stack.push(expr[i] - 48);
				std::cout << PURPLE "pushed: " << _stack.top() << RESET << std::endl;
				i += 2;
			}
			if (i > static_cast<int>(expr.size()))
				break;
			// while there is a valid operation, run executeOperation where it takes pops
			// two numbers from the top of the stack and execute the operation
			while (expr[i] && _op.find(expr[i]) != std::string::npos) {
				// if there is only one number in the stack, you cannot execute operation
				if (_stack.size() < 2) {
					throw invalidExpressionOrder();
				}
				executeOperation(expr[i]);
				i++;
			}
		}
		// if there is more than one number left in the stack after the algorithm, an exception is thrown
		if (_stack.size() != 1)
			throw invalidExpressionOrder();

		std::cout << UGRN << "Result: " << static_cast<int>(_stack.top()) << RESET << std::endl; 
	} catch (const std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
}

void RPN::checkExpressionFormat( const std::string& expr ) {
	int i = 0;

	while (expr[i]) {
		if (isdigit(expr[i]) || _op.find(expr[i]) != std::string::npos)
			i++;
		else
			throw invalidExpressionFormat();
		if (expr[i] == '\0')
			break;
		if (expr[i] == ' ')
			i++;
		else
			throw invalidExpressionFormat();
	}
}

void RPN::executeOperation( const char& op ) {
	int res = 0;
	int num2 = 0;
	int num1 = 0;

	num2 = _stack.top();
	_stack.pop();
	num1 = _stack.top();
	_stack.pop();

	if (op == '+') {
		res = num1 + num2;	
	} else if (op == '-') {
		res = num1 - num2;
	} else if (op == '/') {
		if (num2 == 0) {
			throw divisionByZero();
		}
		res = num1 / num2;
	} else if (op == '*') {
		res = num1 * num2;
	}
	std::cout << CYAN << "calculate: " << num1 << " " << op << " " << num2 << " = " << res << RESET << std::endl;
	_stack.push(res);
}

const char* RPN::invalidExpressionFormat::what() const throw() {
	return "Error: expression format, only accepts:\n\
	integers in the range [0, 10)\n\
	operations [+-/*]\n\
	one space between each number / operation\n\
\n\nExample: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"";
}

const char* RPN::invalidExpressionOrder::what() const throw() {
	return "Error: expression order, please check if your expression is valid";
}

const char* RPN::divisionByZero::what() const throw() {
	return "Error: division by zero";
}


