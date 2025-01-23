/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-02/ex01/Fixed.hpp                        *
*                    Creation Date: January 21, 2025 01:16 PM                    *
*                    Last Updated: January 21, 2025 10:14 AM                     *
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
#include	<cmath>
#include	<iostream>

/********************************************************************************/

typedef int	index;

/********************************************************************************/

int			main(void);

/********************************************************************************/

class	Fixed {
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
	public:
		Fixed(void);
		Fixed(const int integer);
		Fixed(const float floating);
		Fixed(const Fixed &original);
		Fixed &operator=(const Fixed &original);
		~Fixed();

		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		float	toFloat(void) const;
		int		toInt(void) const;

		friend	std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};