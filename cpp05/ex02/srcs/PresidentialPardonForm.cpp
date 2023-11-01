/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:42:24 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/01 21:29:41 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

PresidentialPardonForm::PresidentialPardonForm(): AForm(PRES_FORM_NAME, PRES_SIGN_GRADE, PRES_EXEC_GRADE) {
	std::cout << GREEN << "PresidentialPardonForm with no target is constructed" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ): AForm(PRES_FORM_NAME, PRES_SIGN_GRADE, PRES_EXEC_GRADE) {
	this->_target = target;
	std::cout << GREEN << "PresidentialPardonForm with target " << target << " is constructed" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) {
	(void)other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other ) {
	(void)other;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << RED << "PresidentialPardonForm is destructed" << RESET << std::endl;
}

void PresidentialPardonForm::pardon() const {
	std::cout << PURPLE << this->_target << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}

void PresidentialPardonForm::execute( Bureaucrat const& executor ) const {
	if (this->getIsSigned() == false) {
		throw MyException("Warning: Presidential Pardon Form is unable to execute. It is not signed");
	} else if (this->getGradeRequiredToExec() < executor.getGrade()) {
		throw MyException("Warning: Presidential Pardon Form is unable to execute. Bureaucrat grade is too low");
	}
	this->pardon();
}
