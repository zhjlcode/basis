#include <iostream>
#include <array>

//c++新标准建议使用标准库定义的<array>来定义数组
int main(int argc,char** argv){
    std::array<int,4> arr{1,2,3,4};
    for(auto e : arr){
        std::cout << e << " ";
    }
    std::cout << std::endl;
    for(auto& e : arr){
        std::cout << e * 2 << " ";
    }
    return 0;
}