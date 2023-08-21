## using
 - 头文件不应包含using声明
    ``` cpp
    位于头文件的代码，一般不应使用using声明，因为头文件的内容会被拷贝到所有引用它的文件中。对于某些源文件来说，using声明里的名字可能会和它本身的名字产生冲突
    ```
- :: 作用域操作符
    ``` cpp
    std::cout表示使用std这个名字里的cout
    Person::say()表示使用Person这个类里的say()方法
    ```

- 使用名字空间里的成员
    ``` cpp
    //方法1：std::cin表示使用std里的cin

    //方法2：using std::cin;使用了using声明后，以后用到cin的地方都表示是std这个命名空间里的cin。using使得某个命名空间里的名字在程序内可见。
    ```
- 定义类型别名
    ``` cpp
    //C++11新标准，使用别名声明来定义类型的别名:
    class Person{

    };
    using PS = Person; //PS等同于Person
    ```
- 定义模板别名只能使用using，不能使用typedef

## typedef
- 类型别名
    ``` cpp
    typedef double wages;//wages代表double
    typedef wages base,*p;//base代表double，p代表double*

    //含有typedef的声明语句定义的不再是变量而是类型别名
    ```
- 指针&类型别名&常量
    ``` cpp 
    //首先看声明的格式，声明由数据类型+声明符构成。例如char **p;由数据类型char和声明符**p组成

    typedef char *pstring;//pstring表示的数据类型是char*
    const pstring p1 = 0;//顶层const，p1是常量指针，不能改变p1的值
    const pstring *p2;//底层const，p2是一个指针，p2可以改变，*p2不能改变。p2指向char*类型

    //刨析
    //遇到类型别名的声明语句时，人们往往会错误的把类型别名替换为本来的样子，以理解语句的含义。这种理解是错误的。
    const pstring *p;
    const char **p;
    //使用pstring声明时数据类型是指针；如果替换为char*声明，数据类型是char,*成为了声明符的一部分
    ```