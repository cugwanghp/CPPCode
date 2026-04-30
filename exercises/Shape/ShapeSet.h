#pragma once
#include "Shape.h"
#include <vector>

class ShapeSet{
public:
    ShapeSet()=default;
    ShapeSet(const ShapeSet& other);
    ShapeSet& operator=(const ShapeSet& other);
    ShapeSet(ShapeSet&& other) noexcept;
    ~ShapeSet(); 
    
    bool read(const char* filename);
    int getSize() const;
    double getPerimeter() const;
    double getArea() const;
protected:
    void clone(const ShapeSet& other);
private:
    std::vector<Shape*> shapeVector;
};
