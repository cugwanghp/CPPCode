# C++
## 类与对象
### 封装
- 语法
- 访问权限
- 函数+变量

### 抽象
- 善于发现代码中重复的部分，设计阶段复用（提出来设计类）
- 重复部分封装类
- 只需要关注public接口（函数），protected/private 不关注

### 继承与派生
- 拿来主义
- 新增接口
- 二义性问题（virtual)
- 基类构造的顺序

### 多态
- 覆盖功能（有功能，不适合，重写 override)
- 虚函数（virtual function)
- 调用（Base*， Base& --> 代替了派生类对象）
- __vfptr (虚函数指针数组，间接调用)

### Notes
#### 构造和析构
- 默认构造
- 自定义构造
- 自定义析构
- 构造和析构的顺序

#### 操作符重载
- friend
- member

---
## Shape Example
### 需求
1. 形状的数据，存在一个文件 shape.dat
2. 构建Shape类族(Triangle, Rectangle, Circle)
3. shape对象的统计信息的输出（个数，总的面积，总的周长），输出到文件
4. 绘制形状到屏幕

### 设计
- Shape
- Triangle, Rectangle, Circle
- ShapeSet