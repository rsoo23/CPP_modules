/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:36:25 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/01 14:57:15 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

Form::Form(): _name("no name"), _isSigned(false), _gradeRequiredToSign(LOWEST_GRADE), _gradeRequiredToExec(LOWEST_GRADE) {
	std::cout << GREEN << "Form no name is constructed" << RESET << std::endl;
}

Form::Form( std::string name, int g1, int g2 ): _name(name), _isSigned(false), _gradeRequiredToSign(g1), _gradeRequiredToExec(g2) {
	checkFormGradeRange(g1, g2);
	std::cout << GREEN << "Form " << name << " is constructed" << RESET << std::endl;
}

Form::Form( const Form& other ): _name(other._name), _isSigned(other._isSigned), _gradeRequiredToSign(other._gradeRequiredToSign), _gradeRequiredToExec(other._gradeRequiredToExec) {
	*this = other;
	std::cout << GREEN << "Form is copied" << RESET << std::endl;
}

Form& Form::operator=( const Form& other ) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	std::cout << GREEN << "Form is assigned" << RESET << std::endl;
	return *this;
}

Form::~Form() {
	std::cout << RED << "Form is destructed" << RESET << std::endl;
}

void Form::GradeTooHighException( std::string msg ) {
	throw MyException(msg);
}

void Form::GradeTooLowException( std::string msg ) {
	throw MyException(msg);	
}

const std::string Form::getName() const {
	return this->_name;
}

bool Form::getIsSigned() const {
	return this->_isSigned;
}

int Form::getGradeRequiredToSign() const {
	return this->_gradeRequiredToSign;
}

int Form::getGradeRequiredToExec() const {
	return this->_gradeRequiredToExec;
}

void Form::checkFormGradeRange( int g1, int g2 ) {
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

void Form::beSigned( Bureaucrat& b ) {
	if (this->_isSigned == true) {
		std::cout << RED << this->_name << " couldn't sign " << b.getName() << " because it is already signed" << RESET << std::endl;
	} else if (b.getGrade() <= this->_gradeRequiredToSign) {
		this->_isSigned = true;
		std::cout << YELLOW << this->_name << " is signed by " << b.getName() << RESET << std::endl;
	} else
		GradeTooLowException("Warning: Bureaucrat grade too low to sign form");
}

std::ostream& operator<<( std::ostream& out, const Form& f ) {
	out << CYAN << "Form: " << f.getName() << ", is signed: " << f.getIsSigned() << ", grade required to sign: " << f.getGradeRequiredToSign() << ", grade required to exec: " << f.getGradeRequiredToExec() << RESET;
	return (out);
}
