/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:16:28 by rsoo              #+#    #+#             */
/*   Updated: 2023/12/07 14:12:53 by rsoo             ###   ########.fr       */
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
			while (expr[i] && isdigit(expr[i])) {
				_stack.push(expr[i] - 48);
				std::cout << "pushed: " << _stack.top() << std::endl;
				i += 2;
			}
			while (expr[i] && _op.find(expr[i]) != std::string::npos) {
				executeOperation(expr[i]);
				i++;
			}
		}
		if (_stack.size() != 1)
			throw ;

		std::cout << UCYN << "Result: " << static_cast<int>(_stack.top()) << RESET << std::endl; 
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
	int num2 = _stack.top();
	_stack.pop();
	int num1 = _stack.top();
	_stack.pop();

	if (op == '+') {
		res = num1 + num2;	
	} else if (op == '-') {
		res = num1 - num2;
	} else if (op == '/') {
		res = num1 / num2;
	} else if (op == '*') {
		res = num1 * num2;
	}
	std::cout << "res: " << res << std::endl;
	_stack.push(res);
}

const char* RPN::invalidExpressionFormat::what() const throw() {
	return "Error: expression format, only accepts numbers in the range [0, 10) and operations [+-/*]\
\n\nExample: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"";
}


