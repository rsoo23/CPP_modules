/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:38:44 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/01 21:33:52 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(): _name("no name"), _grade(LOWEST_GRADE) {
	std::cout << GREEN << "Bureaucrat no name is constructed" << RESET << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ): _name(name), _grade(grade) {
	checkGradeRange(grade);
	std::cout << GREEN << "Bureaucrat " << name << " is constructed" << RESET << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) {
	*this = other;
	std::cout << GREEN << "Bureaucrat is copied" << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other ) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	std::cout << GREEN << "Bureaucrat is assigned" << RESET << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << RED << "Bureaucrat is destructed" << RESET << std::endl;
}

void Bureaucrat::GradeTooHighException() {
	throw MyException("Warning: Bureaucrat grade is too high");
}

void Bureaucrat::GradeTooLowException() {
	throw MyException("Warning: Bureaucrat grade is too low");	
}

const std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;	
}

void Bureaucrat::incrementGrade() {
	this->_grade--;
	checkGradeRange(this->_grade);
}

void Bureaucrat::decrementGrade() {
	this->_grade++;
	checkGradeRange(this->_grade);
}

void Bureaucrat::checkGradeRange( int grade ) {
	if (grade < HIGHEST_GRADE) {
		GradeTooHighException();
	} else if (grade > LOWEST_GRADE) {
		GradeTooLowException();
	}
}

void Bureaucrat::signForm( AForm& f ) {
	if (f.getIsSigned() == true) {
		std::cout << RED << this->_name << " couldn't sign " << f.getName() << " because it is already signed" << RESET << std::endl;
	} else if (this->_grade <= f.getGradeRequiredToSign()) {
		f.beSigned(*this);
	} else {
		std::cout << RED << this->_name << " couldn't sign " << f.getName() << " because the bureaucrat grade is too low" << RESET << std::endl;
	}
}

void Bureaucrat::executeForm( AForm const& f ) {
	if (f.getIsSigned() == false) {
		std::cout << RED << this->_name << " couldn't execute " << f.getName() << " because it is not signed"<< RESET << std::endl;
	} else if (this->_grade > f.getGradeRequiredToExec()) {
		std::cout << RED << this->_name << " couldn't execute " << f.getName() << " because the bureaucrat grade is too low" << RESET << std::endl;
	} else
		f.execute(*this);
}

std::ostream& operator<<( std::ostream& out, const Bureaucrat& b ) {
	out << CYAN << b.getName() << ", bureaucrat grade " << b.getGrade() << RESET;
	return (out);
}
