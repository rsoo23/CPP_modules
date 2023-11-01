/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:42:27 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/01 21:30:53 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

RobotomyRequestForm::RobotomyRequestForm(): AForm(ROBO_FORM_NAME, ROBO_SIGN_GRADE, ROBO_EXEC_GRADE) {
	std::cout << GREEN << "RobotomyRequestForm with no target is constructed" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ): AForm(ROBO_FORM_NAME, ROBO_SIGN_GRADE, ROBO_EXEC_GRADE) {
	this->_target = target;
	std::cout << GREEN << "RobotomyRequestForm with target " << target << " is constructed" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) {
	(void)other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& other ) {
	(void)other;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << RED << "RobotomyRequestForm is destructed" << RESET << std::endl;
}

void RobotomyRequestForm::robotomize() const {
	static int i = 0;

	std::cout << PURPLE << "BRRR BRRR ZZZZ BRR ZZZ" << std::endl;
	if (i % 2 == 0) {
		std::cout << UYEL << this->_target << " has been successfully robotomized" << std::endl;
		i++;
	} else {
		std::cout << URED << "Warning: Robotomy for " << this->_target << " has failed" << std::endl;
	}
}

void RobotomyRequestForm::execute( Bureaucrat const& executor ) const {
	if (this->getIsSigned() == false) {
		throw MyException("Warning: Robotomy Request Form is unable to execute. It is not signed");
	} else if (this->getGradeRequiredToExec() < executor.getGrade()) {
		throw MyException("Warning: Robotomy Request Form is unable to execute. Bureaucrat grade is too low");
	}
	this->robotomize();
}
