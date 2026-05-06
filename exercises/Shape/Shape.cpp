#include "Shape.h"

// 圆周率常量：建议用 const 而非 #define，const 有类型且进入编译期检查
const double PI = 3.14159265358979;

double Circle::area() const {
    return PI * radius * radius;
}

void Circle::print() const {
    std::cout << "Circle: r=" << radius << ", area=" << area() << std::endl;
}

double Rectangle::area() const {
    // 使用 std::abs 处理任意对角点顺序：topLeft 和 bottomRight 谁是谁不重要
    double w = std::abs(bottomRight.x - topLeft.x);
    double h = std::abs(bottomRight.y - topLeft.y);
    return w * h;
}

void Rectangle::print() const {
    std::cout << "Rectangle: w=" << std::abs(bottomRight.x - topLeft.x)
              << " h=" << std::abs(bottomRight.y - topLeft.y)
              << ", area=" << area() << std::endl;
}

double Triangle::area() const {
    // 向量叉积公式：|(p2-p1) × (p3-p1)| / 2
    // 二维向量叉积结果为标量：ax*by - ay*bx
    // 这里用展开后的代数形式直接计算
    return 0.5 * std::abs(
        (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y)
    );
}

void Triangle::print() const {
    std::cout << "Triangle: area=" << area() << std::endl;
}
