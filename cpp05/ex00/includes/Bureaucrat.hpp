/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:38:52 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/01 11:12:54 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class MyException: public std::exception {
	public:
		MyException( const std::string& errorMsg ): _errorMsg(errorMsg) {}
		virtual const char *what() const throw() {
			return (this->_errorMsg).c_str();
		}
		virtual ~MyException() throw() {}

	private:
		const std::string _errorMsg;
};

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat( std::string name, int grade );
		Bureaucrat( const Bureaucrat& other );
		Bureaucrat& operator=( const Bureaucrat& other );
		~Bureaucrat();

		void GradeTooHighException();
		void GradeTooLowException();

		const std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void checkGradeRange( int grade );

	private:
		const std::string _name;
		int _grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
