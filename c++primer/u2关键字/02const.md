### const限定符
const限定对象后，对象的值就不能改变，因此const限定的对象必须初始化

默认情况下，const对象仅在本文件内有效。

如果想在多个文件共享const变量，只需要在声明和定义处都加上extern即可。也就是说只在一个文件定义，其他文件声明
``` cpp
//test.h
extern const int var;//声明

//test.cpp
extern const int var = 15;//定义

//main.cpp
#include <iostream>
using std::cout;
#include "test.h"
int main(void)
{
  cout<<var;//输出15
}
```

### const的引用
1.常量引用：形如const int &r = expr;的引用称为常量引用。
  - 说明：一般来说引用只能使用对象进行初始化或赋值<!--03复合类型/###引用-->，但有两个例外，其中一个就是常量引用，见4。


2.常量引用可以引用变量，也可以引用常量。因此常量引用可能引用的是一个变量，也可能是一个常量。
  ``` cpp
  int var{10};
  const int con{20};

  const int &vr{var};//引用变量
  const int &cr{con};//引用常量
  ```


3.不能通过常量引用修改对象的值，不管这个对象是变量还是常量。
  ``` cpp
  int var{10};
  const int con{20};

  const int &vr{var};//引用变量
  vr = 5;//错误：不能通过常量引用修改对象
  var = 5;//正确
  const int &cr{con};//引用常量
  cr = 5;//错误：不能通过常量引用修改对象
  ```


4.常量引用初始化：前面说过，引用的类型要与所绑定的对象的类型一致，但有两个例外。第一个例外就是在初始化常量引用时允许使用任意表达式作为初始值，**只要该表达式的值可以转换为引用的类型即可**
  ``` cpp
  int i = 42;
  const int &r1 = i;//正确
  const int &r2 = 42;//正确
  const int &r3 = r1 * 2;//正确
  int &r4 = r1 * 2;//错误：r4是一个普通的非常量引用

  //刨析，对比常量引用和普通引用 --- 初始化时的不同。 
  //1.常量引用初始化
  double i = 3.14;
  const int &r = i;
  //编译器会将这两句语句进行处理
  const int  tmp = i;
  const int &r = tmp;
  //说明：const类型的引用在初始化时，如果引用的类型和被引用的对象的类型不一致，编译器会做tmp处理

  //2.普通引用初始化
  double i = 3.14;
  int &r = i;//非法行为
  /*
  * 假设编译器也对r做tmp处理的话
    int tmp = i;
    int &r = tmp;
  * r是变量，可以对r赋值。但此时r绑定的是tmp变量，此时我们对r赋值是对tmp赋值，但我们本意是想通过r改变i的值，违背了我们的行为，所以C++把这种行为归为非法。而1中的r为常量时，常量本身不可以改变，因此在1中是合法的
  */
  ```

### 指针和const
``` cpp
int i  = 10;
const int *pi = &i;//*pi不能改变，p可以指向其他对象
int j = 20;
int* const pj = &j;//pj不能改变，*pj可以改变

//准则：要想清楚声明语句的含义，从右往左阅读
```

const指针:
  - 格式：形如int *const p = &i;
  - 因为是常量指针，所以必须初始化，并且p的值不能改变

指针本身是一个对象，它又可以指向另一个对象。因此指针本身是不是常量和指针指向的对象是不是常量是两个相互独立的问题。
  - 顶层const，表示指针本身p是个常量。顶层const作用于对象本身
  - 底层const，表示指针指向的对象*p是常量。底层const作用于指针相关联的对象

顶层const可以泛化地表示任意的对象是常量，如算术类型、类、指针等。底层const与指针和引用等复合类型有关
``` cpp
int i = 0;
int *const p1 = &i;//顶层const，不能修改p1的值
const int *p2  = &i;//底层const，可以修改p2的值
const int &r = i;//用于声明引用的const都是底层const，即引用只有底层const

//执行拷贝操作时，常量是顶层const还是底层const区别明显。这时顶层const可以忽略，但底层const不能忽略。
int j = 0;
const int var1 = 20;//顶层const
int var2 = 30;
int *const p = &j;//底层const
j = var1;//正确：顶层const不受影响
p = &var2;//错误：底层const，当拷入和拷出操作的对象必须具有相同的底层const资格，或者两个对象数据类型能够相互转换。
```