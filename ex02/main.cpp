/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-02/ex02/main.cpp                        *
*                    Creation Date: January 21, 2025 01:30 PM                    *
*                    Last Updated: January 24, 2025 02:36 PM                     *
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
	Fixed	fixedList[] = {	Fixed(Fixed(42.42f) + Fixed(42)),
							Fixed(Fixed(42.42f) - Fixed(42)),
							Fixed(Fixed(42.42f) * Fixed(42)),
							Fixed(Fixed(42.42f) / Fixed(42))};

	for (index i = 0 ; i < 4 ; i++)
		std::cout << BG_YELLOW << "Value of " << i + 1 << ':'  << RESET << ' '  << fixedList[i]   << std::endl;
	std::cout << BG_YELLOW     << "Value when preincrement:"   << RESET << ' '  << ++(*fixedList) << std::endl;
	std::cout << BG_YELLOW     << "Value when postincrement:"  << RESET << '\n' << (*fixedList)++ << std::endl;
	std::cout << BG_YELLOW     << "Value after postincrement:" << RESET << ' '  << *fixedList     << std::endl;
	std::cout << BG_YELLOW     << "Value when predecrement:"   << RESET << ' '  << --(*fixedList) << std::endl;
	std::cout << BG_YELLOW     << "Value when postdecrement:"  << RESET << '\n' << (*fixedList)-- << std::endl;
	std::cout << BG_YELLOW     << "Value after postdecrement:" << RESET << ' '  << *fixedList     << std::endl;
}