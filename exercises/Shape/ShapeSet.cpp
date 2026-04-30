#include "ShapeSet.h"
#include <fstream>
#include <string>
#include <sstream>
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

ShapeSet::ShapeSet(const ShapeSet& other){
    clone(other);
}

void ShapeSet::clone(const ShapeSet& other){
    for (int i=0; i<other.shapeVector.size(); i++){
        if (dynamic_cast<Triangle*>(other.shapeVector[i])){
            shapeVector.push_back(new Triangle(*dynamic_cast<Triangle*>(other.shapeVector[i])));
        }
        else if (dynamic_cast<Rectangle*>(other.shapeVector[i])){
            shapeVector.push_back(new Rectangle(*dynamic_cast<Rectangle*>(other.shapeVector[i])));
        }
        else if (dynamic_cast<Circle*>(other.shapeVector[i])){
            shapeVector.push_back(new Circle(*dynamic_cast<Circle*>(other.shapeVector[i])));
        }
    }
}

ShapeSet& ShapeSet::operator=(const ShapeSet& other){
    if (this != &other){
        for (int i = 0; i < shapeVector.size(); i++){
            delete shapeVector[i];
        }
        shapeVector.clear();

        clone(other);
    }
    return *this;
}   

ShapeSet::ShapeSet(ShapeSet&& other) noexcept{
    shapeVector = other.shapeVector;
    other.shapeVector.clear();
}

ShapeSet::~ShapeSet(){
    for (int i = 0; i < shapeVector.size(); i++){
        delete shapeVector[i];
    }   
} 
    
bool ShapeSet::read(const char* filename){
    // open file -> ifstream
    // 
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    // read shapes from file
    std::string line;
    double a, b, c, w, h, r;
    int type;
    ShapeType shapeType;

    while (file.good()) {
        std::getline(file, line);
        std::istringstream iss(line);
        iss >> type;
        shapeType = static_cast<ShapeType>(type);
        switch(shapeType){
            case ShapeType::TRIANGLE:
                iss >> a >> b >> c;
                shapeVector.push_back(new Triangle(a, b, c));
                break;
            case ShapeType::RECTANGLE:
                iss >> w >> h;
                shapeVector.push_back(new Rectangle(w, h));
                break;
            case ShapeType::CIRCLE:
                iss >> r;
                shapeVector.push_back(new Circle(r));
                break;
            default:
                break;
        }
    }

    file.close();
    return true;
}

int ShapeSet::getSize() const{
    return shapeVector.size();
}

double ShapeSet::getPerimeter() const{
    double perimeter = 0.0;
    for (int i = 0; i < shapeVector.size(); i++){
        perimeter += shapeVector[i]->getPerimeter();
    }
    return perimeter;
}

double ShapeSet::getArea() const{
    double area = 0.0;
    for (int i = 0; i < shapeVector.size(); i++){
        area += shapeVector[i]->getArea();
    }
    return area;
}