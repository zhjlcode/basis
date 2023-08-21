#include <iostream>

//c++17新标准：带初始化的for语句
int main(int argc,char** argv){
    if(auto x{5} ; x > 0) std::cout << x << std::endl;
    auto x{"hello"}; //x可以重用
    std::cout << x << std::endl;
    return 0;
}