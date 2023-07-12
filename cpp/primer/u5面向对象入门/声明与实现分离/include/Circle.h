//#pragma once //预处理，防止头文件重复包含

#ifndef _CIRCLE_H //标准头文件格式，防止头文件重复包含，和#pragma效果一样
#define _CIRCLE_H

#define PI 3.14

class Circle{
private:
    double radius{0.0};
public:
    Circle();
    Circle(double r);
    void printInfo();
};
#endif