格式：
``` cpp
try{
    program-statements
} catch (exception-declaration){
    //exception-declaration是某个异常类对象的声明
    hand-statements
}//...
```

try将可能出现异常的语句括住。如果出现异常就抛出，当选中了某个catch子句的处理异常后，执行对应的块。catch一旦完成，程序跳转到最好一个catch语句的下一条语句继续执行