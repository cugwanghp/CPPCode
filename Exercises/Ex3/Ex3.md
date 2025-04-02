<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2024-03-19 20:13:40
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2024-03-19 20:13:47
-->
# 实习三
\item 设计一个以数组为参数的函数，将数组中的元素从小到大排列。

    \item 用递归算法实现二分查找，即：有20个已经从小到大排序好的数据，
    从键盘输入一个数$X$，用折半查找方法，判断它是否在这20个数中。

    \item 将一个数组中的所有元素倒序存放。
    
    \item 读入n个数，打印其中的最大数及其位置号。
    
    \item 写一个函数实现矩阵的转置:
    $$
    \begin{bmatrix}
        1 & 2 & 3 \\
        4 & 5 & 6 \\
        7 & 8 & 9 \\
        10 & 11 & 12
    \end{bmatrix}
    \longrightarrow
    \begin{bmatrix}
        1 & 4 & 7 & 10 \\
        2 & 5 & 8 & 11 \\
        3 & 6 & 9 & 12 
    \end{bmatrix} 
    $$    
    
    \item 编程实现两字符串的连接。要求使用字符数组保存字符串，不要使用系统函数。
    
    \item 一个由一系列记录组成的数据集，其中每条记录都由以下两个字段组成：
    1）名称，即字符串（不含空白字符）；2）值，即实数。记录和记录中的字段用空白分隔。同一名称可出现在多条记录中。数据集中的记录数可能非常大（如四万亿条记录）。实现一个程序，从标准输入端读取上述类型的数据集，并将以下信息写入标准输出端：
   \begin{enumerate}[1)]
       \item (不同)名称的数量；
       \item 每个名称的最小值、最大值和平均值；
       \item 所有记录的最小值、最大值和平均值。（提示：使用std::map）。
   \end{enumerate}
   
   \item 编写一个函数str\_to\_int，将表示有符号整数的C风格字符串（即由一个可能的正负号和一个或多个数字组成的字符串）转换为相应的数值。
   \begin{enumerate}[1)]
        \item 函数应接受一个指向C风格数字字符串指针的参数，并返回整型 int。如果字符串格式不正确，返回值应为0。

        \item 编写一个测试str\_to\_int函数的程序。同时，用下面的程序测试str\_to\_int函数。
    \end{enumerate}
    \lstinputlisting[language=C++]{code/pop_str_to_int-test.cpp}

    \item 编写一个函数 copy\_ints，用于将指定数量的整数 int 从内存的一个区域复制到另一个区域。
    函数的返回类型应为void,并接受以下参数：1)指定复制操作源区域起始位置的指针；
    2)指定要复制的整数个数；3)指定复制操作目标区域起始位置的指针。
    在下面的程序中测试该函数。
    \lstinputlisting[language=C++]{code/pop_copy_ints_test.cpp}