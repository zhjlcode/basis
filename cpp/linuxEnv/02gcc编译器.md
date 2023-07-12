## 编译过程
- 预处理
    ``` sh
    # -E指示编译器对源文件做预处理，-o指定输出路径
    g++ -E test.cpp -o test.i
    ```

- 编译
    ``` sh
    # -S告诉编译器产生汇编文件后停止
    # g++产生的汇编文件缺省后缀是.s
    g++ -S test.i -o test.s
    ```

- 汇编
    ``` sh
    # -c选项告诉编译器把源代码翻译为机器语言的目标二进制文件
    # g++产生的目标文件缺省后缀是.o
    g++ -c tes.s -o test.o
    ```

- 链接
    ``` sh
    # 生成可执行文件
    g++ test.o -o test

    # ./test执行可执行文件
    ```

## g++部分重要编译参数
- -g 编译带调试信息的可执行文件
    ``` sh
    # 告诉 gcc 产生能被gbd使用的调试信息，用来调试程序
    # 产生带调试信息的可执行文件
    g++ -g test.cpp -o test
    ```
- -O[n] 优化源代码
    ``` sh
    # 优化：例如省略源文件中未使用过的变量、将常量表达式用结果值代替等操作。这些操作会缩减目标文件所含代码量，提高可执行文件运行效率

    -O  同时减小代码长度和执行时间，等价于-O1
    -O0 不做优化
    -O1 默认优化
    -O2 在-O1的基础上，做一些指令调整，告诉编译器产生足够少和快的代码。常用
    -03 循环展开、处理特性相关的优化工作
    ```
    
    ``` sh
    g++ test.cpp -O2 test01
    g++ test.cpp -O0 test02

    # time ./可执行文件：linux内置的查看程序运行时间的命令
    time ./test01
    time ./test02
    ```

- -l和-L
    ``` sh
    # -l 指定链接的库，后面紧跟库名
    # gcc默认从/lib、/usr/lib、/usr/local/lib去查找库
    g++ -lglog test.cpp

    # -L 指定查找库文件的路径，后面紧跟库文件所在目录
    g++ -L/home/zhjl/mylib -lmytest test.cpp 
    ```

- -I
    ``` sh
    # -I指定头文件搜索路径
    # gcc头文件默认搜索路径是/usr/include
    g++ -I/home/zhjl/myinclude test.cpp
    ```

- -Wall
    ``` sh
    # 打印出gcc提供的警告信息
    g++ -Wall test.cpp
    ```

- -W
    ``` sh
    # 关闭警告信息
    g++ -W test.cpp
    ```

- -std=c++11
    ``` sh
    # 设置编译标准
    g++ -std=c++11 test.cpp
    ```

- -o
    ``` sh
    # 指定输出文件名
    # linux中gcc默认输出到a.out中
    g++ test.cpp -o test
    ```
- -D
    ``` cpp
    #include <iostream>

    int main(void){
	    #ifdef DEBUG 
		std::cout<<"123"<<" ";
	    #endif
		std::cout<<"hello"<<std::endl;
	return 0;   
    }
    ```

    ``` sh
    # 定义宏
    g++ -DDEBUG test.cpp test
    ./test #输出hello

    g++ test.cpp
    ./test #输出123 hello
    ```
## 查看gcc命令
man gcc
