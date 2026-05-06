#include "ShapeSet.h"

// 析构函数：逐一 delete 指针
// 注意：
//   - delete nullptr 是安全操作（什么都不做），无需额外判断
//   - 每个 Shape 子类都有虚析构函数，所以这里 delete
//     会正确调用 Circle/Rectangle/Triangle 的析构
ShapeSet::~ShapeSet() {
    for (Shape* shape : shapes) {
        delete shape;
    }
}

void ShapeSet::addShape(Shape* shape) {
    shapes.push_back(shape);  // vector 自动扩容
}

void ShapeSet::printAll() const {
    // const 成员函数：承诺不修改任何成员变量
    // const Shape*：承诺不修改所指向的对象（但可以调用其 const 成员函数）
    for (const Shape* shape : shapes) {
        shape->print();
    }
}

double ShapeSet::totalArea() const {
    double total = 0.0;
    for (const Shape* shape : shapes) {
        total += shape->area();  // 运行时多态：通过基类指针调用子类实现
    }
    return total;
}

int ShapeSet::count() const {
    return shapes.size();  // size_t -> int 隐式转换，安全（数量不会为负）
}
