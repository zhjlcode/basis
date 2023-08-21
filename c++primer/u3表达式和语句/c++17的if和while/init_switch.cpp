#include <iostream>
#include <cstdlib>

//c++17新标准，带初始化的switch
int main(int argc,char** argv){
    switch (auto x{rand() % 100} ; x)
    {
    case 33:
        std::cout << 33;
        break;
    case 66:
        std::cout << 66;
        break;
    case 88:
        std::cout << 88;
        break;
    default:
        break;
    }
    std::cout << std::endl;
    auto x{"init"};
    std::cout << x;//x可以重用
    return 0;
}
