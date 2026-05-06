#pragma once
#include <iostream>
#include <cmath>

// ------------------------------------------------------------
// 基础结构：仅存放数据，无行为
// ------------------------------------------------------------
struct Point {
    double x, y;
};

// ------------------------------------------------------------
// 抽象基类：定义所有图形共同接口
//   - area()  : 计算面积
//   - print() : 输出信息
//   - 虚析构  : 确保通过基类指针删除时调用正确的析构函数
// ------------------------------------------------------------
class Shape {
public:
    // 纯虚函数：子类必须实现，= 0 表示"没有默认实现"
    virtual double area() const = 0;
    virtual void print() const = 0;

    // 虚析构函数 —— 多态删除的保障
    // 若无 virtual，delete BasePtr 时只会调用 Base::~Base()，
    // 而非 Derived::~Derived()，导致子类资源泄漏
    virtual ~Shape() {}
};

// ------------------------------------------------------------
// 圆形：圆心 + 半径
// ------------------------------------------------------------
class Circle : public Shape {
    Point center;     // 私有成员：外部无法直接访问
    double radius;
public:
    Circle(double x, double y, double r) : center{x, y}, radius(r) {}

    double area() const override;  // override 关键字：编译器检查是否真的覆盖了基类虚函数
    void print() const override;
};

// ------------------------------------------------------------
// 矩形：对角两点定义（不限定哪个是左上/右下，代码中通过 abs 处理）
// ------------------------------------------------------------
class Rectangle : public Shape {
    Point topLeft;
    Point bottomRight;
public:
    Rectangle(double x1, double y1, double x2, double y2)
        : topLeft{x1, y1}, bottomRight{x2, y2} {}

    double area() const override;
    void print() const override;
};

// ------------------------------------------------------------
// 三角形：三个顶点
//   面积公式：| (x2-x1)(y3-y1) - (x3-x1)(y2-y1) | / 2
//   即向量叉积的模的一半
// ------------------------------------------------------------
class Triangle : public Shape {
    Point p1, p2, p3;
public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
        : p1{x1, y1}, p2{x2, y2}, p3{x3, y3} {}

    double area() const override;
    void print() const override;
};
