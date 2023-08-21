格式：throw 表达式;
  - 其中，表达式的类型就是抛出的异常类型。

例如：
``` cpp
Sales_item itm1,itm2;
cin>>item1>>item2;
//检测item1和item2是否是同一书籍，如果不是则抛出一个runtime_error对象
if(item1.isbn() != item.isbn()) 
  throw runtime_error{"Data must refer to same ISBN"};
//如果相等则相加
cout<<item1+item2<<endl;

//runtime_error是标准库异常类型的一种，定义在<stdexcept>中。我们必须runtime_erroe的对象，方法是给它提供一个string对象或一个C风格字符串。
