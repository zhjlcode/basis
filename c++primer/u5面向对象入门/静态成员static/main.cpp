#include <iostream>
#include "Square.h"
#include  <cassert>

using std::endl;
using std::cout;

int Square::numberOfObjects = {0};
int main(int argc,char** argv){
    //1.通过对象访问静态成员函数    
    std::cout << "by object...." <<std::endl;
    Square s1;//调用无参构造
    assert(Square::getNumberOfObjects() == 1);
    std::cout << s1.getNumberOfObjects()<< std::endl;
    Square s2{4.0};//调用有参构造
    std::cout << s2.getNumberOfObjects()<< std::endl;

    //2.通过类访问静态成员函数
    std::cout << " by class...." <<std::endl;
    cout << Square::getNumberOfObjects();
    
    return 0;
}