/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                      File Name: /CPP-02/ex03/askFloat.cpp                      *
*                    Creation Date: January 24, 2025 04:02 PM                    *
*                    Last Updated: January 29, 2025 11:14 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                            A bit like a load to do!                            *
*********************************************************************************/

#include "./Point.hpp"

/********************************************************************************/

/**
 * @brief Asks the user to enter a float.
 * 
 * @return float The valid float.
 */
float askFloat() {
	float	number = 0;

	do {
		std::cin >> number;

		if (std::cin.eof()) {
			std::cout << BG_RED "Confirmed CTRL-D:" RESET RED " exit: " RESET
				"Thank you for using " << GREEN << "BSP" RESET "!" << std::endl;
			exit(EXIT_SUCCESS);
		}
		else if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << ERROR << "Invalid input. Enter a float value!" << RESET << std::endl;
		}
		else
			break;
		std::cout << std::endl;
	} while (forever);

	return number;
}