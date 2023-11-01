/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:36:25 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/01 20:40:13 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

AForm::AForm(): _name("no name"), _isSigned(false), _gradeRequiredToSign(LOWEST_GRADE), _gradeRequiredToExec(LOWEST_GRADE) {
	std::cout << GREEN << "AForm no name is constructed" << RESET << std::endl;
}

AForm::AForm( std::string name, int g1, int g2 ): _name(name), _isSigned(false), _gradeRequiredToSign(g1), _gradeRequiredToExec(g2) {
	checkFormGradeRange(g1, g2);
	std::cout << GREEN << "AForm " << name << " is constructed" << RESET << std::endl;
}

AForm::AForm( const AForm& other ): _name(other._name), _isSigned(other._isSigned), _gradeRequiredToSign(other._gradeRequiredToSign), _gradeRequiredToExec(other._gradeRequiredToExec) {
	(void)other;
	std::cout << GREEN << "AForm is copied" << RESET << std::endl;
}

AForm& AForm::operator=( const AForm& other ) {
	(void)other;
	return *this;
}

AForm::~AForm() {
	std::cout << RED << "AForm is destructed" << RESET << std::endl;
}

void AForm::GradeTooHighException( std::string msg ) {
	throw MyException(msg);
}

void AForm::GradeTooLowException( std::string msg ) {
	throw MyException(msg);	
}

const std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getIsSigned() const {
	return this->_isSigned;
}

int AForm::getGradeRequiredToSign() const {
	return this->_gradeRequiredToSign;
}

int AForm::getGradeRequiredToExec() const {
	return this->_gradeRequiredToExec;
}

void AForm::checkFormGradeRange( int g1, int g2 ) {
	if (g1 < HIGHEST_GRADE) {
		GradeTooHighException("Warning: Grade Required to Sign is too high");
	} else if (g1 > LOWEST_GRADE) {
		GradeTooLowException("Warning: Grade Required to Sign is too low");
	} 
	if (g2 < HIGHEST_GRADE) {
		GradeTooHighException("Warning: Grade Required to Execute is too high");
	} else if (g2 > LOWEST_GRADE) {
		GradeTooLowException("Warning: Grade Required to Execute is too low");
	}
}

void AForm::beSigned( Bureaucrat& b ) {
	if (this->_isSigned == true) {
		std::cout << RED << this->_name << " couldn't sign " << b.getName() << " because it is already signed" << RESET << std::endl;
	} else if (b.getGrade() <= this->_gradeRequiredToSign) {
		this->_isSigned = true;
		std::cout << YELLOW << this->_name << " is signed by " << b.getName() << RESET << std::endl;
	} else
		GradeTooLowException("Warning: Bureaucrat grade too low to sign form");
}

std::ostream& operator<<( std::ostream& out, const AForm& f ) {
	out << CYAN << "AForm: " << f.getName() << ", is signed: " << f.getIsSigned() << ", grade required to sign: " << f.getGradeRequiredToSign() << ", grade required to exec: " << f.getGradeRequiredToExec() << RESET;
	return (out);
}
