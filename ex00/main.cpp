/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-02/ex00/main.cpp                        *
*                    Creation Date: January 21, 2025 01:30 PM                    *
*                    Last Updated: January 21, 2025 03:48 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                     The main test program of the exercise                      *
*********************************************************************************/

#include "./Fixed.hpp"

/********************************************************************************/

static inline void	printInstruction(const std::string &line);
static inline void	printValues(Fixed &a, Fixed &b, Fixed &c, Fixed *d);

/********************************************************************************/

/**
 * @brief A simple test program that operates on the Fixed class.
 * 
 * @return int The status of the program as ended.
 */
int main(void) {
	try {
		printInstruction("Fixed	a, b;\nFixed	c(a);");
		Fixed	a, b;
		Fixed	c(a);
		printValues(a, b, c, NULL);

		printInstruction("b = a;");
		b = a;
		printValues(a, b, c, NULL);

		printInstruction("c.setRawBits(7);");
		c.setRawBits(7);
		printValues(a, b, c, NULL);

		printInstruction("b.setRawBits(77);");
		b.setRawBits(77);
		printValues(a, b, c, NULL);

		printInstruction("Fixed	d(c);");
		Fixed	d(c);
		printValues(a, b, c, &d);

		printInstruction("d = b;");
		d = b;
		printValues(a, b, c, &d);

		printInstruction("");
		return EXIT_SUCCESS;
	} catch (...) {
		std::cout << ERROR << "Something went wrong. I'll blame std::string!" << RESET << std::endl;
		return EXIT_FAILURE;
	}
}

/**
 * @brief Prints with an internal index the desired instruction line.
 * 
 * @param line Operated instruction.
 */
static inline void	printInstruction(const std::string &line) {
	static index	instruction = 1;

	if (!line.empty()) {
		std::cout << '\n' << READABLE_BG_BRIGHT_WHITE << "=== INSTRUCTION " << instruction++ << " ===" << RESET << '\n' << std::endl;
		std::cout << line << '\n' << std::endl;
	}
	else
		std::cout << '\n' <<READABLE_BG_BRIGHT_WHITE << "=== END OF INSTRUCTIONS ===" << RESET << '\n' << std::endl;
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
	printInstruction("int	aValue = a.getRawBits();\nint	bValue = b.getRawBits(); \nint	cValue = c.getRawBits();\nint	dValue = -1;\nif (d)\n	dValue = d->getRawBits();\n\nstd::cout << aValue << ' ' << bValue << ' ' << cValue << ' ' << dValue << std::endl;");

	int	aValue = a.getRawBits();
	int	bValue = b.getRawBits(); 
	int	cValue = c.getRawBits();
	int	dValue = -1;
	if (d)
		dValue = d->getRawBits();

	std::cout << aValue << ' ' << bValue << ' ' << cValue << ' ' << dValue << std::endl;
}