/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-02/ex02/Fixed.hpp                        *
*                    Creation Date: January 21, 2025 01:16 PM                    *
*                    Last Updated: January 24, 2025 02:36 PM                     *
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
#include	<limits>

#include	<termios.h>
#include	<unistd.h>
#include	<iomanip>

/********************************************************************************/

typedef int	index;

#define forever	1
#define SIGNAL	'\033'

/********************************************************************************/

int		main(void);
float	askFloat(void);
bool	exitLoop(bool set);

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

		friend	std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};