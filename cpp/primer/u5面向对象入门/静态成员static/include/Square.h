#pragma once

class Square{
private:
    double side{1.0};//边长
    static int numberOfObjects;
public:
    double getSide(){return this->side;}
    void setSide(double side){this->side = side;}
    Square(double side){
        this->side = side;
        ++numberOfObjects;
    }
    Square():Square(1.0){}//委托构造
    double getArea(){return side * side;};
    static int getNumberOfObjects(){return numberOfObjects;}
};