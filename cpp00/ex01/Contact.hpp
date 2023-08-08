/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 22:10:55 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/08 22:10:55 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Contact {
    public:
        Contact();
        ~Contact();
        void    setIndex(int index);
        void    setInfo();

    private:
        int         index;
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
}
