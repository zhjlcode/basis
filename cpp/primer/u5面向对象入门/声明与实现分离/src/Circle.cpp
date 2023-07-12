#include "Circle.h"
#include <iostream>

Circle::Circle(){}
Circle::Circle(double r){
    this -> radius = r; 
}
void Circle::printInfo(){
    std::cout<< PI * radius *radius << std::endl;
}