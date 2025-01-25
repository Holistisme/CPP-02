/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-02/ex02/main.cpp                        *
*                    Creation Date: January 21, 2025 01:30 PM                    *
*                    Last Updated: January 25, 2025 11:15 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                     The main test program of the exercise                      *
*********************************************************************************/

#include "./Point.hpp"

/********************************************************************************/

static void			setTriangleAndCheckPoint(void);
static inline void	aBeautifulDay(const Point &a, const Point &b, const Point &c, const Point &p);
static inline Point	newPoint(char position);
static inline void	erasePreviousLines(const size_t &count);

/********************************************************************************/

/**
 * @brief A simple test program that operates on the Fixed class.
 * 
 * @return int The status of the program as ended.
 */
int main(void) {
	try {
		std::cout << std::fixed << std::setprecision(2);
		std::cout << "\n◬ Welcome to an " << BG_YELLOW << "ESSENTIAL" << RESET << " program to calculate if a point is in a triangle! ◬\n" << std::endl;
		setTriangleAndCheckPoint();
		erasePreviousLines(2);
		std::cout << "◬ How dare you stop this " << BG_YELLOW << "ESSENTIAL" << RESET << " program to calculate if a point is in a triangle! ◬\n" << std::endl;
		return EXIT_SUCCESS;
	} catch (...) {
		std::cout << ERROR << "Something went wrong. I'll blame std::string!" << RESET << std::endl;
		return EXIT_FAILURE;
	}
}

/**
 * @brief Creates a triangle with user entries to check that it contains a given point.
 * 
 */
static void	setTriangleAndCheckPoint(void) {
	while (forever) {
		Point a = newPoint('a');
		if (exitLoop(false)) {
			erasePreviousLines(1);
			return;
		}

		Point b = newPoint('b');
		if (exitLoop(false)) {
			erasePreviousLines(7);
			return;
		}

		Point c = newPoint('c');
		if (exitLoop(false)) {
			erasePreviousLines(13);
			return;
		}

		while (forever) {
			Point p = newPoint('p');
			if (exitLoop(false)) {
				erasePreviousLines(19);
				break;
			}
			if (bsp(a, b, c, p))
				std::cout << GREEN << "Point P is in the triangle!" << RESET << std::endl;
			else
				std::cout << RED << "Point P is not in the triangle!" << RESET << std::endl;
			sleep(3);
			aBeautifulDay(a, b, c, p);
			erasePreviousLines(6);
		}
	}
}

/**
 * @brief An essential function to check if the data entered in the points form an iconic date.
 * 
 * @param a A first point.
 * @param b A second point.
 * @param c A third point.
 * @param p A fourth point.
 */
static inline void	aBeautifulDay(const Point &a, const Point &b, const Point &c, const Point &p) {
	const int	dateInteger[] = {1, 9, 8, 7, 0, 7, 2, 7};
	const int	pointInteger[] = {
		a.getXCoordinates().toInt(), a.getYCoordinates().toInt(),
		b.getXCoordinates().toInt(), b.getYCoordinates().toInt(),
		c.getXCoordinates().toInt(), c.getYCoordinates().toInt(),
		p.getXCoordinates().toInt(), p.getYCoordinates().toInt()};

	for (index i = 0 ; i < 8 ; i++)
		if (dateInteger[i] != pointInteger[i])
			return;

	#ifdef __linux__
		system("xdg-open https://www.youtube.com/watch?v=dQw4w9WgXcQ > /dev/null 2>&1");
	#elif _WIN32
		system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ > nul 2>&1");
	#elif __APPLE__
		system("open https://www.youtube.com/watch?v=dQw4w9WgXcQ > /dev/null 2>&1");
	#endif
}

/**
 * @brief Shapes the creation of a new point.
 * 
 * @param position The letter from the point.
 * @return Point The new point.
 */
static inline Point	newPoint(char position) {
	float	x, y;

	std::cout << "Define the new point " << BLUE << position << RESET << ":" << std::endl;
	for (index i = 0 ; i < 2 ; i++) {
		std::cout << "What will be its value: " << YELLOW << (!i ? 'x' : 'y') << RESET << ':' << std::endl << std::endl;
		!i ? x = askFloat() : y = askFloat();
		if (exitLoop(false)) {
			!i ? erasePreviousLines(2) : erasePreviousLines(4);
			exitLoop(true);
			return Point(0, 0);
		}
	}
	if (position != 'p')
		std::cout << std::endl;
	return Point(x, y);
}

/**
 * @brief Erase the previous `count` lines from the terminal.
 * 
 * This function uses the ANSI escape sequence defined in `ERASE_LINE` 
 * to clear the specified number of lines from the terminal output.
 * 
 * @param count The number of lines to erase.
 */
static inline void	erasePreviousLines(const size_t &count) {
	std::string	eraseInstructions = "";

	for (size_t index = 0 ; index < count ; index++)
		eraseInstructions += ERASE_LINE;

	std::cout << eraseInstructions << std::flush << MOVE_CURSOR_UP << std::endl;
}

/**
 * @brief A function that saves the user's output key.
 * 
 * @param set If a new data, records, otherwise just checks.
 * @return true If the exit button has been a press.
 * @return false If nothing new.
 */
bool	exitLoop(bool set) {
	static bool	save = false;

	if (set)
		return save = true;
	return (save ? save = false, true : false);
}