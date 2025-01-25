/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                      File Name: /CPP-02/ex03/askFloat.cpp                      *
*                    Creation Date: January 24, 2025 04:02 PM                    *
*                    Last Updated: January 24, 2025 05:13 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                            A bit like a load to do!                            *
*********************************************************************************/

#include "./Point.hpp"

/********************************************************************************/

static inline void	enableRawMode();
static inline void	disableRawMode();

/********************************************************************************/

/**
 * @brief Allows the user to gradually enter a float with the arrows.
 * 
 * @return float The return of the user's progressive entry.
 */
float	askFloat(void) {
	float	number = 0;
	enableRawMode();

	while (forever) {
        std::cout << ERASE_LINE << (number >= 0 ? GREEN : RED) << number << RESET << std::endl;

		char	key;
		read(STDIN_FILENO, &key, 1);

		if (key == SIGNAL) {
			char	seq[2];

			read(STDIN_FILENO, &seq[0], 1);
			read(STDIN_FILENO, &seq[1], 1);

			if (*seq == '[') {
				if (seq[1] == 'A')
					number += 1;
				else if (seq[1] == 'B')
					number -= 1;
				else if (seq[1] == 'C')
					number += 0.01;
				else if (seq[1] == 'D')
					number -= 0.01;
			}
        }
		else if (key == '\n')
			return number;
		else if (key == 'q' or key == 'Q') {
			exitLoop(true);
			return number;
		}
    }
    disableRawMode();
}

/**
 * @brief Disables the written mirror and long message functions on the terminal.
 * 
 */
static inline void	enableRawMode() {
	struct termios	raw;

	tcgetattr(STDIN_FILENO, &raw);
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

/**
 * @brief Reactivates the terminal by default.
 * 
 */
static inline void	disableRawMode() {
	struct termios	original;
	tcgetattr(STDIN_FILENO, &original);

	original.c_lflag |= (ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &original);
}