/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:42:30 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/01 21:30:32 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm(SHRUB_FORM_NAME, SHRUB_SIGN_GRADE, SHRUB_EXEC_GRADE) {
	std::cout << GREEN << "ShrubberyCreationForm with no target is constructed" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): AForm(SHRUB_FORM_NAME, SHRUB_SIGN_GRADE, SHRUB_EXEC_GRADE) {
	this->_target = target;
	std::cout << GREEN << "ShrubberyCreationForm with target " << target << " is constructed" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) {
	(void)other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other ) {
	(void)other;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << RED << "ShrubberyCreationForm is destructed" << RESET << std::endl;
}

void ShrubberyCreationForm::createAsciiTree() const {
	std::ofstream outputFile(this->_target + "_shrubbery");

	if (outputFile.is_open()) {
		
		for (int i = 0; i < ASCII_TREE_HEIGHT; i++) {
			outputFile << ASCII_TREE[i] << std::endl;
		}
		
		outputFile.close();
		std::cout << UCYN << "Shrubbery file created successfully" << std::endl;
	} else {
		std::cerr << "Failed to open the file" << std::endl;
	}
}

void ShrubberyCreationForm::execute( Bureaucrat const& executor ) const {
	if (this->getIsSigned() == false) {
		throw MyException("Warning: Shrubbery Creation Form is unable to execute. It is not signed");
	} else if (this->getGradeRequiredToExec() < executor.getGrade()) {
		throw MyException("Warning: Shrubbery Creation Form is unable to execute. Bureaucrat grade is too low");
	}
	this->createAsciiTree();
}
