#include "Base.h"

constexpr float PI = 3.1415926;

float Circle::area() const {
		return PI * radius*radius;
}

float Rectangle::area() const {
		return width * height;
}