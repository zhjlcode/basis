### Lambda表达式举例
``` java
//演示Lambda表达式和方法引用的写法
//Lambda前提：适用于函数式接口
public class Lambda01 {
    public static void main(String[] args) {
        
    }
    @Test
    public void test1(){
        //1.使用匿名内部类来使用接口,传统方法
        IA ia1 = new IA() {
            @Override
            public void say() {
                System.out.println("我爱北京...");
            }
        };
        ia1.say();
        //Lambda表达式
        IA ia2 = ()-> System.out.println("我爱南京...");
        ia2.say();
    }

    @Test
    public void test2(){
        //传统形式
        Comparator<Integer> com1 = new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return Integer.compare(o1,o2);
                //compare方法，返回一个int = o1-o2;
            }
        };
        System.out.println(com1.compare(12,21));
        //Lambda表达式的写法
        Comparator<Integer> com2 = (o1,o2)->Integer.compare(o1,o2);
        System.out.println(com2.compare(12,21));
        //方法引用的写法
        Comparator<Integer> com3 = Integer::compare;
        System.out.println(com3.compare(12,21));
    }
}
interface IA{
    public void say();
}
```

### Lambda表达式说明
``` java
/*
* 演示Lambda表达式的六种情况
* 1.举例(o1,o2)->Integer.compare(o1,o2);
* 2.格式：
        ->:Lambda操作符，或箭头操作符
        ->左边：形参列表，其实就是接口中的抽象方法形参列表
        ->右边：Lambda体，其实就是重写的抽象方法的方法体
* 3.Lambda表达式的使用，分为六种情况介绍
* 4.java中Lambda表达式本质：最好看做是一个函数，但可以赋值给函数式接口类型的变量;当传递给函数式接口类型的变量时，JVM会生成一个该接口类型的对象。(该对象实现了接口的方法，该对象的方法体为lambda体)
*/
public class Lambda02 {
    public static void main(String[] args) {
    }

    //格式一：无参无返回值
    @Test
    public void test01() {
        //传统
        IA2 i1 = new IA2() {
            @Override
            public void say() {
                System.out.println("我爱北京");
            }
        };
        i1.say();
        //Lambda写法
        IA2 i2 = () -> { System.out.println("我爱南京");};//左边为接口抽象方法形参，右边为重写的抽象方法的方法体
        i2.say();
    }

    //格式二：需要一个参数，但没有返回值
    @Test
    public void test02(){
        //传统
        Consumer<String> c1= new Consumer<String>() {
            @Override
            public void accept(String s) {
                System.out.println(s);
            }
        };
        c1.accept("hello");
        //Lambda写法
        Consumer<String> c2 = (String s)->{System.out.println(s);};//左边为接口抽象方法形参，右边为重写的抽象方法的方法体
        c2.accept("world");
    }

    //格式三：数据类型可以省略，因为可以由编译器推断出，称为数据推断
    @Test
    public void test03(){
        Consumer<String> c = (s)->{System.out.println(s);};//左边为接口抽象方法形参，右边为重写的抽象方法的方法体
        c.accept("hello,world");
    }

    //格式四：若Lambda只需要一个参数，参数的小括号可以省略
    @Test
    public void test04(){
        Consumer<String> c = s->{System.out.println(s);};
        c.accept("hello,world");
    }

    //格式五：Lambda需要两个或以上的参数，多条执行语句，并且可以有返回值
    @Test
    public void test05(){
        //传统形式
        Comparator<Integer> c1 = new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                System.out.println(o1);
                System.out.println(o2);
                return o1.compareTo(o2);
            }
        };
        System.out.println(c1.compare(15,20));
        //Lambda
        //Lambda表达式是对接口使用匿名内部实例化对象的一种简写
        Comparator<Integer> c2 = (o1,o2)->{
            System.out.println(o1);
            System.out.println(o2);
            return o1.compareTo(o2);
        };
        System.out.println( c2.compare(15,20));
    }

    //格式六：当Lambda体只有一条语句时，return与大括号若有，都可以省略
    @Test
    public void test06(){
        Comparator<Integer> c = (o1,o2)->o1.compareTo(o2);
        System.out.println(c.compare(15,20));
    }
}

interface IA2 {
    public void say();
}
```

### 总结
适用场景：需要使用函数式接口，但又不想创建对象实现该接口时，可以使用匿名内部类实例化，而匿名内部类又可以使用Lambda简写
->左边：Lambda形参类型可以省略(类型推断)；如果只有一个形参，其()也可以省略；无参数则需要提供一个()
->右边：Lambda体应该使用一对{}包住；如果Lambda体只有一条语句(有可能是return语句)，可以省略这一对{}和return关键字
⭐⭐⭐注意：
*   仅针对函数式接口使用，==接口需要是函数式接口，即该接口只声明了一个抽象方法==
#### 四大函数式接口
![什么是函数式接口](images/2022-09-30-16-47-05.png)
![如何理解函数式接口](images/2022-09-30-16-50-49.png)
![四大核心函数式接口](images/2022-09-30-17-26-34.png)
![其他函数式接口](images/2022-09-30-17-26-01.png)

