/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-02/ex01/Fixed.cpp                        *
*                    Creation Date: January 21, 2025 01:30 PM                    *
*                    Last Updated: January 21, 2025 10:13 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*             All the management functions of a well-tracked fixed!              *
*********************************************************************************/

#include "./Fixed.hpp"

/********************************************************************************/

/**
 * @brief Construct a new Fixed object.
 * 
 */
Fixed::Fixed(void) : _fixedPointValue(0) {
	std::cout << BRIGHT_BLUE << this << RESET << ": Default constructor called." << std::endl;
}

/**
 * @brief Construct a new Fixed object.
 * 
 * @param original Constructs the object by copying this.
 */
Fixed::Fixed(const Fixed &original) {
	std::cout << BRIGHT_GREEN << this << RESET << ": Copy constructor called." << std::endl;
	*this = original;
}

/**
 * @brief Destroy the Fixed object.
 * 
 */
Fixed::~Fixed() {
	std::cout << BRIGHT_RED << this << RESET << ": Destructor called." << std::endl;
}

/**
 * @brief Allows to assign a fixed in relation to another.
 * 
 * @param original The source of the copy.
 * @return Fixed& The object with the new same properties.
 */
Fixed &Fixed::operator=(const Fixed &original) {
	std::cout << BRIGHT_YELLOW << this << RESET << ": Copy assignment operator called." << std::endl;

	if (this != &original)
		_fixedPointValue = original._fixedPointValue;

	return *this;
}

/**
 * @brief Sets the point value of the Fixed object.
 * 
 * @param raw The new value.
 */
void	Fixed::setRawBits(int const raw) {
	std::cout << BRIGHT_MAGENTA << this << RESET << ": " << BOLD << "setRawBits()" << RESET << " member function called." << std::endl;
	_fixedPointValue = raw;
}

/**
 * @brief Gets the point value of the Fixed object.
 * 
 * @return int The point value.
 */
int		Fixed::getRawBits(void) const {
	std::cout << BRIGHT_MAGENTA << this << RESET << ": " << BOLD << "getRawBits()" << RESET << " member function called." << std::endl;
	return _fixedPointValue;
}

/********************************************************************************/
/*************************** New exercise functions! ****************************/
/********************************************************************************/

/**
 * @brief Construct a new Fixed object using an integer!
 * 
 * @param integer the integer to configure.
 */
Fixed::Fixed(const int integer) : _fixedPointValue(integer << _fractionalBits) {
	std::cout << BRIGHT_CYAN << this << RESET << ": Int constructor called." << std::endl;
}

/**
 * @brief Construct a new Fixed object using a float!
 * 
 * @param floating the float to configure.
 */
Fixed::Fixed(const float floating) : _fixedPointValue(static_cast<int>(roundf(floating * (1 << _fractionalBits)))) {
	std::cout << BRIGHT_CYAN << this << RESET << ": Float constructor called." << std::endl;
}

float	Fixed::toFloat(void) const	{ return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits); };
int		Fixed::toInt(void) const	{ return _fixedPointValue >> _fractionalBits; };

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