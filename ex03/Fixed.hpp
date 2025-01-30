/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-02/ex03/Fixed.hpp                        *
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

#include	<cmath>
#include	<cstdlib>
#include	<iomanip>
#include	<iostream>
#include	<limits>

/********************************************************************************/

typedef int	index;

#define forever	1
#define SIGNAL	'\033'

/********************************************************************************/

int		main(void);
float	askFloat(void);

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
		bool operator>(const Fixed &another) const;
		bool operator<(const Fixed &another) const;
		bool operator>=(const Fixed &another) const;
		bool operator<=(const Fixed &another) const;
		bool operator==(const Fixed &another) const;
		bool operator!=(const Fixed &another) const;
		Fixed operator+(const Fixed &target) const;
		Fixed operator-(const Fixed &target) const;
		Fixed operator*(const Fixed &target) const;
		Fixed operator/(const Fixed &target) const;
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		~Fixed();

		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);