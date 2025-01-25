/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-02/ex02/Fixed.cpp                        *
*                    Creation Date: January 21, 2025 01:30 PM                    *
*                    Last Updated: January 24, 2025 02:36 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*             All the management functions of a well-tracked fixed!              *
*********************************************************************************/

#include "./Fixed.hpp"

/********************************************************************************/

static inline bool	checkResult(const float &result);

/********************************************************************************/

Fixed::Fixed(void)					: _fixedPointValue(0) {}
Fixed::Fixed(const int integer)		: _fixedPointValue(integer << _fractionalBits) {}
Fixed::Fixed(const float floating)	: _fixedPointValue(static_cast<int>(roundf(floating * (1 << _fractionalBits)))) {}

Fixed::Fixed(const Fixed &original)	{*this = original;}

Fixed::~Fixed() {}

void	Fixed::setRawBits(int const raw) {_fixedPointValue = raw;}
int		Fixed::getRawBits(void) const	 { return _fixedPointValue; }


float	Fixed::toFloat(void) const { return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits); };
int		Fixed::toInt(void)   const { return _fixedPointValue >> _fractionalBits; };

/**
 * @brief Allows to assign a fixed in relation to another.
 * 
 * @param original The source of the copy.
 * @return Fixed& The object with the new same properties.
 */
Fixed &Fixed::operator=(const Fixed &original) {
	if (this != &original)
		_fixedPointValue = original._fixedPointValue;

	return *this;
}

/**
 * @brief The custom display operator for the class.
 * 
 * @param out display output.
 * @param fixed the class itself.
 * @return std::ostream& the output still in itself.
 */
std::ostream	&operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

/********************************************************************************/
/********************** Compare the values ​​of two numbers ***********************/
/********************************************************************************/

bool Fixed::operator>(const Fixed &another)  const	{ return getRawBits() > another.getRawBits(); 	}
bool Fixed::operator<(const Fixed &another)	 const	{ return getRawBits() < another.getRawBits(); 	}
bool Fixed::operator>=(const Fixed &another) const	{ return getRawBits() >= another.getRawBits();	}
bool Fixed::operator<=(const Fixed &another) const	{ return getRawBits() <= another.getRawBits();	}
bool Fixed::operator==(const Fixed &another) const	{ return getRawBits() == another.getRawBits();	}
bool Fixed::operator!=(const Fixed &another) const	{ return getRawBits() != another.getRawBits();	}

/********************************************************************************/
/******** Performs a calculation on two numbers and ensures no overflow *********/
/********************************************************************************/

Fixed Fixed::operator+(const Fixed &target)	const {
	float	result = toFloat() + target.toFloat();

	return (checkResult(result) ? Fixed(result) : Fixed(toFloat()));
}

Fixed Fixed::operator-(const Fixed &target)	const {
	float	result = toFloat() - target.toFloat();

	return (checkResult(result) ? Fixed(result) : Fixed(toFloat()));
}

Fixed Fixed::operator*(const Fixed &target)	const {
	float	result = toFloat() * target.toFloat();

	return (checkResult(result) ? Fixed(result) : Fixed(toFloat()));
}

Fixed Fixed::operator/(const Fixed &target)	const {
	float	result = toFloat() / target.toFloat();

	return (checkResult(result) ? Fixed(result) : Fixed(toFloat()));
}

Fixed &Fixed::operator++() {
	if (checkResult(getRawBits() + 1))
		++_fixedPointValue;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed	tmp = *this;

	if (checkResult(getRawBits() + 1))
		++_fixedPointValue;
	return tmp;
}

Fixed &Fixed::operator--() {
	if (checkResult(getRawBits() - 1))
		--_fixedPointValue;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed	tmp = *this;

	if (checkResult(getRawBits() - 1))
		--_fixedPointValue;
	return tmp;
}

/********************************************************************************/
/*********************** Returns the largest/small value ************************/
/********************************************************************************/

Fixed		&Fixed::min(Fixed &a, Fixed &b)				{ return (a.getRawBits() < b.getRawBits()) ? a : b; }
Fixed		&Fixed::max(Fixed &a, Fixed &b)				{ return (a.getRawBits() > b.getRawBits()) ? a : b; }
Fixed const &Fixed::min(const Fixed &a, const Fixed &b)	{ return (a.getRawBits() < b.getRawBits()) ? a : b; }
Fixed const &Fixed::max(const Fixed &a, const Fixed &b) { return (a.getRawBits() > b.getRawBits()) ? a : b; }

/**
 * @brief Checks the result of a calculation and refuses it if it encounters a problem.
 * 
 * @param result The result of a float calculation.
 * @return true If no error is encountered.
 * @return false If any problem is detected.
 */
static inline bool	checkResult(const float &result) {
	if (result != result) {
		std::cout << ERROR << "The result of an operation is not a number!" << RESET << std::endl;
		return false;
	}
	else if (result == std::numeric_limits<float>::infinity() or result == -std::numeric_limits<float>::infinity()) {
		std::cout << ERROR << "The result of an operation has gone towards infinity!" << RESET << std::endl;
		return false;
	}
	else if (result && (result > -1e-37f && result < 1e-37f)) {
		std::cout << ERROR << "The result of an operation is too close to zero!" << RESET << std::endl;
		return false;
	}
	return true;
}