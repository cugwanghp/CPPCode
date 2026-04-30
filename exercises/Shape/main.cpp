#include "ShapeSet.h"
#include <iostream>

int main() {
    //1. Read shape.dat --> ShapeSet
    ShapeSet shapeSet;
    if (!shapeSet.read("shape.dat")) {
        std::cerr << "Error reading shape.dat" << std::endl;
        return 1;
    }

    //2. 计算函数
    int size = shapeSet.getSize();
    double perimeter = shapeSet.getPerimeter();
    double area = shapeSet.getArea();

    //3. 输出结果
    std::cout << "Size: " << size << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;
    std::cout << "Area: " << area << std::endl;

    return 0;
}