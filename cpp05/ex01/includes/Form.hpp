/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:35:18 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/01 15:05:34 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

#ifndef FORM_HPP
# define FORM_HPP

class Form {
	public:
		Form();
		Form( std::string name, int g1, int g2 );
		Form( const Form& other );
		Form& operator=( const Form& other );
		~Form();

		void GradeTooHighException( std::string msg );
		void GradeTooLowException( std::string msg );

		const std::string getName() const;
		bool getIsSigned() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExec() const;
	
		void checkFormGradeRange( int g1, int g2 );

		void beSigned( Bureaucrat& b );

	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeRequiredToSign;
		const int _gradeRequiredToExec;
};

std::ostream& operator<<( std::ostream& out, const Form& f );

#endif
