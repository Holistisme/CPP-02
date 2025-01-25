/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-02/ex03/Point.cpp                        *
*                    Creation Date: January 24, 2025 02:59 PM                    *
*                    Last Updated: January 25, 2025 11:45 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                   All internal functions to the point class                    *
*********************************************************************************/

#include "./Point.hpp"

/********************************************************************************/

Point::Point(void)							: _x(0), _y(0) {}
Point::Point(const float x, const float y)	: _x(x), _y(y) {}

Point::Point(const Point &original)			: _x(original._x), _y(original._y) {}

Point::~Point(void) {}

Point &Point::operator=(Point &original)	{ return original; }

Fixed	Point::getXCoordinates(void) const { return _x; }
Fixed	Point::getYCoordinates(void) const { return _y; }