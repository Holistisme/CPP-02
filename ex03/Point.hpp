/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-02/ex03/Point.hpp                        *
*                    Creation Date: January 24, 2025 02:42 PM                    *
*                    Last Updated: January 25, 2025 11:42 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                      Definition to create a point in space                     *
*********************************************************************************/

#pragma	once

/********************************************************************************/

#include	"./Fixed.hpp"
#include	"./output.hpp"

/********************************************************************************/

class	Point {
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point(void);
		Point(const float x, const float y);

		Point(const Point &original);

		Point	&operator=(Point &original);

		~Point(void);

		Fixed	getXCoordinates(void) const;
		Fixed	getYCoordinates(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);