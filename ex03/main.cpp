/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-02/ex03/main.cpp                        *
*                    Creation Date: January 21, 2025 01:30 PM                    *
*                    Last Updated: January 29, 2025 11:14 AM                     *
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
		Point b = newPoint('b');
		Point c = newPoint('c');

		while (forever) {
			Point p = newPoint('p');
			std::cout << std::endl;
			if (bsp(a, b, c, p))
				std::cout << GREEN << "Point P is in the triangle!\n" << RESET << std::endl;
			else
				std::cout << RED << "Point P is not in the triangle!\n" << RESET << std::endl;
			aBeautifulDay(a, b, c, p);
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
		std::cout << "What will be its value: " << YELLOW << (!i ? 'x' : 'y') << RESET << ':' << std::endl;
		!i ? x = askFloat() : y = askFloat();
	}
	if (position != 'p')
		std::cout << std::endl;
	return Point(x, y);
}