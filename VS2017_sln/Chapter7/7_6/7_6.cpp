//7_6.cpp
#include "Derived.h"

int main() {
    Derived d;
    Derived *p = &d;

		process(d);	//

    d.var = 1;	//对象名.成员名标识
    d.fun();	//访问Derived类成员

    d.Base1::var = 2;	//作用域分辨符标识
    d.Base1::fun();	//访问Base1基类成员

    p->Base2::var = 3;	//作用域分辨符标识
    p->Base2::fun();	//访问Base2基类成员

    return 0;
}
