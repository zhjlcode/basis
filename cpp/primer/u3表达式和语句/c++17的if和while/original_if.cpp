#include <iostream>

//传统if
int main(int argc,char** argv){
    auto x{5};
    if(x > 0) std::cout << x << std::endl;
    auto x{"hello"}; //x不可以重用，会报错
    std::cout << x << std::endl;
    return 0;
}