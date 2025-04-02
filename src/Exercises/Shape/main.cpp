#include <iostream>
#include "Shape.h"

int main()
{
    Shape*  pShps[3]{nullptr};

    pShps[0] = new Triangle(3.0, 4.0, 5.0);
    pShps[1] = new Rectangle(3.0, 4.0);
    pShps[2] = new Circle(3.0);

    for (auto& pshp : pShps)
    {
        if (pshp)
            std::cout << pshp->area() << std::endl;
    }

    for (auto& pshp : pShps)
        delete pshp;

    return 0;
}