/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-02/ex00/Fixed.hpp                        *
*                    Creation Date: January 21, 2025 01:16 PM                    *
*                    Last Updated: January 29, 2025 11:14 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                   All the information to become a fixed pro!                   *
*********************************************************************************/

#pragma	once

/********************************************************************************/

#include	"./output.hpp"

/********************************************************************************/

#include	<cstdlib>
#include	<iostream>

/********************************************************************************/

typedef int	index;

/********************************************************************************/

int	main(void);

/********************************************************************************/

class	Fixed {
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &original);
		Fixed &operator=(const Fixed &original);
		~Fixed();

		void	setRawBits(int const raw);
		int		getRawBits(void) const;
};