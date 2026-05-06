#pragma once
#include "Shape.h"

// ------------------------------------------------------------
// 工厂模式：用整数 type 创建对应图形对象
//   优点：创建逻辑集中在一处，main.cpp 无需知道每种图形的构造函数
//   type -> Shape* 映射表在 .cpp 中实现，对外只暴露接口
// ------------------------------------------------------------
class ShapeFactory {
public:
    // params 数组格式（与 main.cpp 解析顺序一致）：
    //   type=0: params[0]=x, params[1]=y, params[2]=radius
    //   type=1: params[0..3] = x1,y1,x2,y2
    //   type=2: params[0..5] = x1,y1,x2,y2,x3,y3
    // 返回值：创建成功返回 Shape*，失败返回 nullptr（由调用方判断）
    static Shape* createShape(int type, const double params[]);
};
