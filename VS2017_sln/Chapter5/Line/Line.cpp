#include "Line.h"
#include <cmath>
//Line 访问 Point 私有成员，
//friend --> 
float Line::length() const {
		float dx = pts[0].x - pts[1].x;
		float dy = pts[0].getY() - pts[1].getY();
		return sqrt(dx*dx + dy * dy);
}