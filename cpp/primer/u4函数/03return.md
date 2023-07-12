### renturn语句形式
return终止当前正在执行的函数并将控制权返回到调用该函数的地方。

return语句有两种格式：
  - return;
  - return expression;

函数遇见return便会退出当前正在执行的函数。类似迭代语句中的break。

### 无返回值函数
没有返回值的函数只能用于返回类型为void的函数中。

返回void类型的函数不要求必须有return语句，如果没有，函数在最后会隐式执行return。

一个返回类型为void的函数也能使用return语句的第二种形式。不过要求expression必须是void返回类型的函数。强行令void函数返回其他类型会产生编译错误。

``` cpp
void swap(int &v1,int &v2)
{
  if(v1==v2) return;
  int tmp = v2;
  v2 = v1;
  v1 = tmp;
  //此处无需显示的return语句，函数可以隐式执行
}

void print(int &v1,int &v2)
{
  return swap(v1,v2);
  //正确：swap返回类型为void
}
```

### 有返回值函数
return 语句返回值的类型必须与函数的返回类型相同或者能隐式转换成函数的返回类型。

1.不要返回局部对象的引用或指针。函数执行结束后，这个函数的栈空间就被释放了，局部对象也就随之释放掉了。如果返回的是局部对象的引用或指针，return语句指向的是不可再用的内存空间。

``` cpp
const string& fun()
{
  string s{};
  if(!set.empty()) return s;//错误：返回局部对象引用
  else return "empty";//错误：empty是一个局部临时变量
}
```

2.函数的返回类型决定函数调用是否是左值。调用一个返回类型为引用的函数得到左值，其他返回类型得到右值。
``` cpp
char& get_va(string &s,string::size_type index)
{
  return string[0];//返回的是左值，char&
}
int main(int argc,char *argv[])
{
  string s{"hello"};
  cout<<s<<endl;
  get_val(s,s.size()) = 'A';
}
```

3.列表初始化返回值。C++11新标准规定，函数可以返回花括号包围的列表值。
``` cpp
vector<string> process()
{
  //...
  //...expected和actual是string对象

  if(expected.empty()) return {};
  //返回空的vector对象
  else if(expected == actual ) return {"fine","okay"};
  //返回列表初始化的vector对象
  else return{"function","fine","okay"};

  //说明：类似其它返回结果，这里的列表用来初始化  表示函数返回的临时变量。
}
```

4.main函数的返回值。
``` cpp
/* 
  1.前面说过，如果函数返回类型不是void，那么必须返回一个值。但main函数除外，main函数可以使用return;
  2.main函数如果没写reutrn语句，编译器会隐式插入一条返回值为0的return语句
  3.返回0表示执行成功，其他值表示失败。为了使返回值和机器无关。我们使用<cstdlib>内定义的两个预处理变量
    * return EXIT_FAILURE;
    * return EXIT_SUCCESS;
*/

#include <cstdlib>
int main()
{
  if(some_failure) return EXIT_FAILURE;
  else return EXIT_SUCCESS;
}
```

### 递归
如果一个函数调用了它自身，不管这种调用是直接还是间接的，都称该函数为递归函数

在递归函数中，一定有某条路径是不包含递归调用的，递归结束条件。否则函数将永远递归下去，直到程序栈空间耗尽。

``` cpp
//例如，使用递归求val的阶乘
int factorial(int val)
{
  if(val>1) 
  return val * factorial(val-1);
  return 1;
}
```

### 返回数组指针或引用
因为数组不能被拷贝，所以函数不能返回数组。不过函数可以返回数组的指针或引用。

定义返回数组的指针或引用的函数过程繁琐。我们可以使用以下方法简化任务。

说明：以指针为例，下面的技巧对引用也适用。

1.使用类型别名简化返回数组指针或引用
``` cpp
//定义一个返回类型为int[2];
typedef int arrT[2];//arrT是一个类型别名,表示int[2]
using arrT = int[2];//等价

arrT* fun(int i);//返回一个int(*)[2]的指针
```

2.未使用类型别名
``` cpp
//1.如果在声明返回类型为数组的引用或指针时，我们必须要牢记数组的维度。
int arr[10];
int *p1[10];//size = 10，type = int*
int (*p2)[10]{&arr};//指针，指向含有十个整数的数组

/*2.再探arr和&arr
int ptr1 = arr;
int (*ptr2)[10]{&arr}
* arr和&arr得到的都是arr这一片内存空间的起始地址，也就是数组首元素的地址。但
  * ptr代表int*类型，指向一个整数
  * ptr2代表int(*)[10]，指向一整个数组。
            
  * ptr1和ptr2的数值虽然相等。但意义完全不同，一个是代表指向一个整数这么大的空间。另一个代表的是指向一个数值这么大的空间。* 如果从底层来看，忽略数据类型。ptr1代表的是4B的空间大小，而ptr2则是代表40B的空间大小。
*/

//3.不适用类型别名定义返回类型为数值指针或引用的函数
int (*(fun(int i)[10];
//fun(int i)表示调用fun函数时需要一个int类型的实参
//(*fun(int i))表示可以对函数调用的结果解引用
//int (*fun(int i))[10]表示解引用函数调用的结果得到的是一个大小为10的数值
```

3.使用尾置返回类型
  - C++11新标准规定函数可以使用尾置返回类型。**任何函数的定义都能使用尾置返回，而不仅仅是局限于数组指针或引用**。这种方式对于返回类型比较复杂的函数很高效。
  - 格式：auto fun(int i) -> 返回类型

``` cpp 
//使用尾置返回简化上面的函数
auto fun(int i) -> int(*)[10];
```

4.使用decltype
  - 如果我们知道函数返回的指针指向哪一个数组，就可以使用decltype关键字声明返回类型。

``` cpp
int odd[]{1,2,3};
int even[]{4,5,6};
decltype(odd) *arr(int i)
{
  return (i % 2) ? &odd : &even;//返回int(*)[3]类型;
}
//decltype表示函数返回类型是个指针，并且指针指向的类型与odd的类型一样。
```
