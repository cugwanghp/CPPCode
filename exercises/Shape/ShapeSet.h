#pragma once
#include "Shape.h"
#include <vector>

// ------------------------------------------------------------
// ShapeSet：图形容器，管理所有 Shape* 指针的生命周期
//
// 所有权说明：
//   - ShapeSet 拥有图中所有指针，析构时会 delete 它们
//   - 其他代码获取指针后不应 delete，也不要悬垂使用
//
// Rule of Zero：
//   只需要手写析构函数（因为有原始指针资源），
//   拷贝构造/赋值 = delete 防止double delete，
//   移动操作使用 = default（vector 的移动语义安全）
// ------------------------------------------------------------
class ShapeSet {
    std::vector<Shape*> shapes;  // 存储所有图形指针
public:
    ShapeSet() = default;        // 允许默认构造（vector 自构造）

    // 析构函数：必须手动实现——逐一 delete 每个指针
    // 若不实现，vector 的元素被销毁时只会销毁指针本身，不调用 delete
    ~ShapeSet();

    // 禁止拷贝：两个 ShapeSet 共享同一批指针 → double delete
    ShapeSet(const ShapeSet&) = delete;
    ShapeSet& operator=(const ShapeSet&) = delete;

    // 移动操作：使用默认语义（vector 指针直接交换，src 变空后析构安全）
    // ShapeSet(ShapeSet&&) = default;
    // ShapeSet& operator=(ShapeSet&&) = default;

    void addShape(Shape* shape);     // 接管指针所有权
    void printAll() const;          // 遍历并调用每个图形的 print()
    double totalArea() const;        // 累加所有图形面积
    int count() const;              // 返回图形个数
};
