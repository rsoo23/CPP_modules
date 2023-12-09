/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:42:49 by rsoo              #+#    #+#             */
/*   Updated: 2023/12/07 23:42:49 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h"

#pragma once

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe( const PmergeMe& other );
        PmergeMe& operator=( const PmergeMe& other );
		~PmergeMe();

        template <typename container>
        void fordJohnsonAlgorithm( container& c );

        // time
        void startClock();
        void stopClock();
        void calculateDuration( const std::string& containerName );

        // error checking
        void assignInputToContainers( int ac, char **av );
        void checkSorted();
        void checkDuplicates();

        // printing
        void printOutput( char **av );
        template <typename container>
        void printContainerElements( container& c, const std::string& containerName );

        // getters
        std::vector<int>& getVec();
        std::list<int>& getLst();
		
        // exceptions
        class inputHasDuplicate: public std::exception {
			public:
				const char* what() const throw();
		};

		class inputHasNegative: public std::exception {
			public:
				const char* what() const throw();
		};

		class inputIsSorted: public std::exception {
			public:
				const char* what() const throw();
		};

		class inputNotNumber: public std::exception {
			public:
				const char* what() const throw();
		};

    private:
        std::vector<int> _vec;
        std::list<int> _lst;
        struct timeval _startTime;
        struct timeval _endTime;
        int _vecSortDuration;
        int _lstSortDuration;

};
