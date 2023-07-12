## C风格数组和C++风格数组
- C风格数组，也叫做c++原生数组
    ``` cpp
    int arr[]{1,2,3};

    1.arr可能会退化为指针
    2.arr不知道自己的大小：sizeof(arr)/sizeof(arr[0])
    3.两个数组间不能直接赋值: array1 = array2 //error
    4.不能自动推导类型 auto arr[] = {1,2,3}
    ``` 
- C++风格数组
    ``` cpp
    #include <array>

    1.是一个容器类，所以有迭代器
    2.两个数组直接可以直接赋值
    3.知道自己大小：size()
    4.能和另一个数组交换内容：swap()
    5.能以指定值填充自己：fill()
    6.取某个位置的元素（做越界检测）：at()
    ```
## array的初始化
- array是c++11提供的模板类，推荐使用array，不推荐使用原生数组
- array初始化格式
    ``` cpp
    std::array<type,number> variable_name{...};
    //variable_name是一个std::arrat<type,number>类型的变量，type和number也是类型的一部分
    ```
- c++17引入了一种新特性，可以对类模板的参数进行推导
    ``` cpp
    #include <iostream>
    #include <array>

    int main(int argc,char** argv){
        std::array<int , 3> arr1{};
        std::array arr2{1,2,3};//c++17新特性，推断出了arr2的参数为3个int型
    }
## array常用方法