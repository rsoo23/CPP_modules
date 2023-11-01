/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:42:11 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/01 20:38:52 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

#ifndef AFORM_HPP
# define AFORM_HPP

class AForm {
	public:
		AForm();
		AForm( std::string name, int g1, int g2 );
		AForm( const AForm& other );
		AForm& operator=( const AForm& other );
		virtual ~AForm();

		void GradeTooHighException( std::string msg );
		void GradeTooLowException( std::string msg );

		const std::string getName() const;
		bool getIsSigned() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExec() const;
	
		void checkFormGradeRange( int g1, int g2 );

		void beSigned( Bureaucrat& b );
		virtual void execute( Bureaucrat const& executor ) const = 0;

	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeRequiredToSign;
		const int _gradeRequiredToExec;
};

std::ostream& operator<<( std::ostream& out, const AForm& f );

#endif
