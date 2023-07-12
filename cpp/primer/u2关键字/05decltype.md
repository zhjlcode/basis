decltype的作用是返回参数的类型，但不会初始化变量。
  
1.参数为函数时，返回的是函数返回值的类型：
``` cpp
int test();
decltype(test) x;//x为int类型
```

2.表达式为变量时，返回变量的类型(包含const、引用和指针)
``` cpp
int i = 0;
const int &r = i;
const int *p = i;
decltype(r) v1 = 0;//const int&
decltype(p) v2 = nullptr;//const int*
```

3.参数为表达式时，返回表达式的结果。例如*p和r+0
  - 表达式结果是左值时，返回引用。假设p是int*类型，则decltype(\*p)返回int&
  - 表达式结果是右值时，返回结果的数据类型。假设p是int*类型，则decltype(&p)返回int**类型

  ``` cpp
  int i = 0;&r = i;*p = &i;
  decltype(r+0) x;//返回int
  decltype(r);//返回int &
  decltype(*p);//变量为*p时，返回引用类型，int &
  decletype(*p+0);//返回int
  ```

特别的：decltype(())，双括号时，永远返回引用。