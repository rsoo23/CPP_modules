/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:15:21 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/02 13:28:52 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

#ifndef INTERN_HPP
# define INTERN_HPP

class Intern {
	public:
		Intern();
		Intern( Intern const& other );
		Intern& operator=( Intern const& other );
		~Intern();

		AForm* makeForm( std::string formName, std::string target );

		AForm* ShrubberyCreate( std::string target );
		AForm* RobotomyRequest( std::string target );
		AForm* PresidentialPardon( std::string target );
};

#endif
