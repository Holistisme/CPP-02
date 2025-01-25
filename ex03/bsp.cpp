/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-02/ex03/bsp.cpp                         *
*                    Creation Date: January 24, 2025 02:59 PM                    *
*                    Last Updated: January 25, 2025 11:35 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                      Checks if a point is in a triangle.                       *
*********************************************************************************/

#include "./Point.hpp"

/********************************************************************************/

static inline float	getCrossProduct(Point const vectA, Point const vectB, Point const vectP);

/********************************************************************************/

/**
 * @brief Checks if the point is in the triangle "abc".
 * 
 * @param a The point a of the triangle.
 * @param b The point b of the triangle.
 * @param c The point c of the triangle.
 * @param point The point to check.
 * @return true If the point is in the triangle.
 * @return false If the point is outside the triangle.
 */
bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	float	vectorABP = getCrossProduct(a, b, point);
	float	vectorBCP = getCrossProduct(b, c, point);
	float	vectorCAP = getCrossProduct(c, a, point);

	return	(vectorABP > 0 and vectorBCP > 0 and vectorCAP > 0)
			or
			(vectorABP < 0 and vectorBCP < 0 and vectorCAP < 0);
}

/**
 * @brief Calculates the cross product between three points.
 * 
 * @param vectA Point A of a vector.
 * @param vectB Point B of a vector.
 * @param vectP Point P of a vector.
 * @return float The position of point P compared to the vector AB (positive if left, negative if on the right).
 */
static inline float	getCrossProduct(Point const vectA, Point const vectB, Point const vectP) {
	return (vectB.getXCoordinates().toFloat() - vectA.getXCoordinates().toFloat())
		* (vectP.getYCoordinates().toFloat() - vectA.getYCoordinates().toFloat())
		- (vectB.getYCoordinates().toFloat() - vectA.getYCoordinates().toFloat())
		* (vectP.getXCoordinates().toFloat() - vectA.getXCoordinates().toFloat());
}