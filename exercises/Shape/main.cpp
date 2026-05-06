#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "ShapeFactory.h"
#include "ShapeSet.h"

// ------------------------------------------------------------
// Shape.dat 格式（每行一个图形，空行或 # 开头的行忽略）：
//   type params...
//
//   type=0 : Circle    ->  x y radius
//   type=1 : Rectangle -> x1 y1 x2 y2
//   type=2 : Triangle  -> x1 y1 x2 y2 x3 y3
//
// 示例：
//   0 0 0 5       # 圆：圆心(0,0)，半径5
//   1 0 0 20 20   # 矩形：对角点(0,0)和(20,20)
//   2 0 0 10 10 20 20  # 三角形：三点(0,0)(10,10)(20,20)
// ------------------------------------------------------------

int main() {
    // ShapeSet 构造：vector 初始化为空
    ShapeSet set;

    // 打开数据文件：相对路径，相对于程序运行时的工作目录
    std::ifstream fin("Shape.dat");
    if (!fin) {
        // 文件打开失败时cerr（不缓冲）比cout更合适用于错误信息
        std::cerr << "Cannot open Shape.dat" << std::endl;
        return 1;
    }

    // 按行读取文件：getline 会保留换行符之前的内容
    std::string line;
    while (std::getline(fin, line)) {
        // 跳过空行和以 # 开头的注释行
        if (line.empty() || line[0] == '#') continue;

        // 将一行字符串按空格拆分成流，再提取数据
        std::istringstream iss(line);
        int type;
        iss >> type;  // 第一个整数是图形类型

        // 从流中依次读取所有 double 到 vector
        // 不知道一行有多少个参数？用 vector 动态扩容，不用固定大小的数组
        std::vector<double> params;
        double p;
        while (iss >> p) {
            params.push_back(p);
        }

        // 工厂创建：校验失败返回 nullptr，正常返回 Shape*
        // 传入 params.data() —— vector 底层是连续数组，相当于 double[]
        Shape* shape = ShapeFactory::createShape(type, params.data());
        if (shape) {
            set.addShape(shape);  // 成功创建才加入集合
        }
        // 失败时 ShapeFactory 已打印错误信息，此处无需额外处理
    }

    fin.close();  // 文件读取完毕，显式关闭（也可以依赖析构函数自动关闭）

    // 输出结果
    set.printAll();
    std::cout << "Total count: " << set.count() << std::endl;
    std::cout << "Total area: " << set.totalArea() << std::endl;

    // 程序结束：set 析构，依次 delete 所有图形，内存自动释放
    return 0;
}
