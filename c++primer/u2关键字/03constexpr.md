## 常量表达式
1.常量表达式是指`编译期可以计算值`，并且`值不会改变`的一个表达式。
``` cpp
//例如：c++数组大小要求是编译期的一个常量（原生数组以及std::array）
int n = 1;
n++;
std::array<int,n a1; //error：n不是常量表达式

const int cn = 2;
std::array<int,cn a2; //true：cn是编译期常量

//但存在一个问题，const修饰的变量不一定是编译期常量，const修饰变量只表示变量是only read的
const int rcn = n; //rcn是运行期常量
rcn = ++n; //rcn 只可读，不可写，但不是编译期常量
``` 

## constexpr
1.一个对象(或表达式)是不是常量表达式由它的数据类型和初始值共同决定
``` cpp
const int exp1 = 20;//exp1是常量表达式
const int exp2 = exp1 + 1;//exp2是常量表达式
int exp3 = exp1 + 1;//exp3不是常量表达式
const int exp4 = fun();//exp4不是常量表达式。
```
2.C++11新标准规定：`声明为constexpr的变量一定是一个常量表达式，而且必须初始化且只能用常量表达式初始化。`
``` cpp
constexpr int mf = 20;//20是常量表达式
constexpr int limit = mf + 1;//mf+1是常量表达式
constexpr int sz = size();//只有当size()是一个constexpr函数时才是正确的语句，否则会报错
```

3.指针和constexpr
``` cpp
//如果在constexpr声明中定义了一个指针，限定符constexpr仅对指针有效，与指针指向对象无关
const int *p = nullptr;//p是一个指向整型常量的指针，p可以改变
constexpr int *q = nullptr;//q是一个指向整型常量指针，q不可以改变

说明：p是一个指向整型常量的指针，q是一个指向整型的常量指针。其中关键在于constexpr把它所定义的对象置为了顶层const。
```