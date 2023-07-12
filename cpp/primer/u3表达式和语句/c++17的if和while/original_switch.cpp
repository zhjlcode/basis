#include <iostream>
#include <cstdlib>

//传统switch
int main(int argc,char** argv){
    auto x = rand() % 100;
    switch (x)
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
    auto x{"original"};
    std::cout << x;//x不能重用
    return 0;
}