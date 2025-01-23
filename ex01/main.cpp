/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-02/ex01/main.cpp                        *
*                    Creation Date: January 21, 2025 01:30 PM                    *
*                    Last Updated: January 21, 2025 10:13 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                     The main test program of the exercise                      *
*********************************************************************************/

#include "./Fixed.hpp"

/********************************************************************************/

static inline void	displayFixed(void);

/**
 * @brief A simple test program that operates on the Fixed class.
 * 
 * @return int The status of the program as ended.
 */
int main(void) {
	try {
		displayFixed();
		return EXIT_SUCCESS;
	} catch (...) {
		std::cout << ERROR << "Something went wrong. I'll blame std::string!" << RESET << std::endl;
		return EXIT_FAILURE;
	}
}

/**
 * @brief Shows some tests for the exercise.
 * 
 */
static inline void	displayFixed(void) {
	Fixed		a;
	Fixed const	b(10), c(42.42f), d(b);

	a = Fixed(1234.4321f);

	std::cout << '\n' << READABLE_BG_BRIGHT_WHITE << "== Welcome to the test part! ==" << RESET << '\n' << std::endl;

	const Fixed	*fixedList[] = {&a, &b, &c, &d};
	const char	letter[] = {'a', 'b', 'c', 'd'};
	for (index i = 0 ; i < 4 ; i++) {
		const int	rawBitsValue = fixedList[i]->getRawBits();

		std::cout << GREEN << letter[i] << RESET
			<< " is " << BLUE << *fixedList[i] << RESET << " (as fixed value), "
			<< YELLOW << fixedList[i]->toInt() << RESET << " (as integer) and " 
			<< RED << rawBitsValue << RESET << " (as rawBits value)!\n" << std::endl;
	}

	std::cout << READABLE_BG_BRIGHT_WHITE << "== End of the test part! ==" << RESET << '\n' << std::endl;
}