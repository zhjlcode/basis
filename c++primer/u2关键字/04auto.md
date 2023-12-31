Q1：注意区分表达式和语句

Q2：在编程时，要将表达式的值赋给变量，就需要在声明变量的时候清楚的知道表达式的类型，然而有时候表达式的值无法确定，也就无法确定变量类型。
解决办法：C++11引入了auto类型说明符，它让编译器替我们分析表达式所属的类型。auto让编译器通过初始值来推算变量的类型。

容易看出，auto定义的变量必须有初始值，否则编译器无法推断出变量的类型
``` cpp
int i = 5;
double j = 3.14;
auto x = i+j;//x为double类型
``` 

编译器推断出来的auto类型有时和初始值的类型并不完全一样，编译器会适当地改变结果类型使它更符合初始化规则：
``` cpp
//例如
int i = 0;&r = i;
auto a = r;//a是int类型
```

auto一般情况下会忽略顶层const，保留底层const。例如当初始值是一个指向常量的指针时：
``` cpp
//1.auto&常量&复合类型
const int i = 0,&r = i;
auto a = i;//a是一个int类型，顶层const被忽略了
auto b = r;//b是int类型
auto c = &i;//c是const int*类型
auto d = &r;//d是const int*类型

//2.如果希望推断出的auto类型是一个顶层const，需要明确指出
const auto f = i;//f是一个const int类型

//3.还可以将引用设置为auto，原来规则一样适用
auto &r1 = i;
auto &r2 = 40;//错误：不能为非常量引用绑定字面值
const auto &r3 = 40;//正确：常量引用

//4.在一条语句中定义多个auto变量时，切记：&和*属于声明符的一部分，而非某个数据类型的一部分，因此初始值必须相同
auto x = 5,y = 10;//正确：x,y都为int类型
auto r = 5,p = &x;//错误：初始值类型不同
```
