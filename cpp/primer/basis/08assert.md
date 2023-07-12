## assert
1.C语言的宏(Macro)，运行时检测，不能当成正常程序的一部分

2.assert是一种预处理宏。预处理宏其实是一个预处理变量。作用于一条表示条件的表达式，可以用于程序调试。

3.格式：assert(expression)
``` cpp
//首先对expr求值
如果表达式为假(0)，assert输出信息并终止程序执行
如果表达式为真(非0),assert什么也不做。

//assert定义在\<cassert>中，预处理名字由预处理器管理而非编译器。所以可以直接使用预处理名字，即应该使用assert而不是std::assert
assert(isTrue); //right
std::assert(isTrue); //erroe
```

4.预处理宏和预处理变量一样，它们的名字在程序内必须唯一。因此不能再定义和它们同名的变量、函数或其他实体。


## NDEBUG
1.assert的行为依赖于一个名为NDEBUG的预处理变量的状态。
``` cpp 
  如果定义了NDEBUG则assert什么也不做

  默认情况下：
        Debug模式编译时，编译器不会定义NDEBUG，assert起作用
        Release模式编译时，编译器自动定义NDEBUG，assert不起作用

        可以手动#define NDEBUG
        #undef NDEBUG //强制以debug模式使用<cassert>
```

2.我们可以使用#define语句定义NDEBUG，从而关闭调试状态。

3.定义NDEBUG能避免各种条件所需的允许时开销，此时不会执行运行时检查。

4.利用NDEBUG进行代码调试
``` cpp
#define NDEBUG

//除了assert可以用于调试外，也可以使用NDEBUG进行条件代码调试。例如下面：如果未定义NDEBUG，将执行#ifndef和#endif之间的代码；如果定义了NDEBUG，这些代码会被忽略。

void print(const int ia[],size_t size)
{
  #ifndef NDEBUG
  //_ _func_ _是编译器定义的一个局部静态变量，用于存放函数名字。
    cerr <<_ _func_ _<< ":array size is" << size <<< endl;
  #endif
}
```

## 调试名字
`编译器`为每个函数都定义了_ _func_ _，它是const char类型的一个静态数组，用于存放函数的名字。

除了C++编译器定义的_ _fun_ _之外，`预处理器`还定义了另外四个用于调试的名字。
  - _ _FILE_ _ 存放文件名的字符串字面值
  - _ _LINE_ _ 存放当前行号的整型字面值
  - _ _TIME_ _ 存放文件编译时间的字符串字面值
  - _ _DATE_ _ 存放文件编译日期的字符串字面值
