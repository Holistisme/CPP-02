/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-02/ex00/main.cpp                        *
*                    Creation Date: January 21, 2025 01:30 PM                    *
*                    Last Updated: January 28, 2025 04:18 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                     The main test program of the exercise                      *
*********************************************************************************/

#include "./Fixed.hpp"

/********************************************************************************/

static inline void	printValues(Fixed &a, Fixed &b, Fixed &c, Fixed *d);

/********************************************************************************/

/**
 * @brief A simple test program that operates on the Fixed class.
 * 
 * @return int The status of the program as ended.
 */
int main(void) {
	try {
		Fixed	a, b;
		Fixed	c(a);
		printValues(a, b, c, NULL);

		b = a;
		printValues(a, b, c, NULL);

		c.setRawBits(7);
		printValues(a, b, c, NULL);

		b.setRawBits(77);
		printValues(a, b, c, NULL);

		Fixed	d(c);
		printValues(a, b, c, &d);

		d = b;
		printValues(a, b, c, &d);

		return EXIT_SUCCESS;
	} catch (...) {
		std::cout << ERROR << "Something went wrong. I'll blame std::string!" << RESET << std::endl;
		return EXIT_FAILURE;
	}
}

/**
 * @brief Shows the values ​​of all Fixed classes.
 * 
 * @param a The first Fixed.
 * @param b The second Fixed.
 * @param c The third Fixed.
 * @param d The fourth and optional Fixed.
 */
static inline void	printValues(Fixed &a, Fixed &b, Fixed &c, Fixed *d) {
	int	aValue = a.getRawBits();
	int	bValue = b.getRawBits(); 
	int	cValue = c.getRawBits();
	int	dValue = -1;
	if (d)
		dValue = d->getRawBits();

	std::cout << aValue << ' ' << bValue << ' ' << cValue << ' ' << dValue << std::endl;
}