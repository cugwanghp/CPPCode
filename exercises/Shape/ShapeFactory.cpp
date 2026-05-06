#include "ShapeFactory.h"
#include <cmath>
#include <iostream>

// 校验函数：检查半径是否合法（> 0）
//   为什么不放在 Circle 构造函数里？
//   因为构造函数无法返回"创建失败"——构造函数没有返回值。
//   工厂方法通过返回 nullptr 来表达失败，调用方负责判断。
static bool validateRadius(double r) {
    if (r <= 0) {
        std::cerr << "Error: invalid Circle radius " << r << " (must be > 0)" << std::endl;
        return false;
    }
    return true;
}

// 校验函数：检查矩形是否退化（宽或高为 0）
static bool validateRectangle(double x1, double y1, double x2, double y2) {
    double w = std::abs(x2 - x1);
    double h = std::abs(y2 - y1);
    if (w <= 0 || h <= 0) {
        std::cerr << "Error: invalid Rectangle with zero or negative area" << std::endl;
        return false;
    }
    return true;
}

// 校验函数：检查三角形是否退化（三点共线面积为 0）
//   浮点数比较用 epsilon：面积 < 1e-9 即认为是 0
static bool validateTriangle(double x1, double y1, double x2, double y2,
                              double x3, double y3) {
    double area = 0.5 * std::abs(
        (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)
    );
    if (area < 1e-9) {
        std::cerr << "Error: degenerate Triangle (three collinear points), area ~= 0" << std::endl;
        return false;
    }
    return true;
}

Shape* ShapeFactory::createShape(int type, const double params[]) {
    switch (type) {
        case 0: {  // Circle
            if (!validateRadius(params[2])) return nullptr;
            return new Circle(params[0], params[1], params[2]);
        }
        case 1: {  // Rectangle
            if (!validateRectangle(params[0], params[1], params[2], params[3])) return nullptr;
            return new Rectangle(params[0], params[1], params[2], params[3]);
        }
        case 2: {  // Triangle
            if (!validateTriangle(params[0], params[1], params[2], params[3],
                                   params[4], params[5])) return nullptr;
            return new Triangle(params[0], params[1], params[2], params[3],
                                  params[4], params[5]);
        }
        default: {
            std::cerr << "Error: unknown shape type " << type << std::endl;
            return nullptr;
        }
    }
}
