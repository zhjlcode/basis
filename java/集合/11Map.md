### Map
Map特性
- HashMap无序，LinkedHashMap有序，TreeMap可排序
- 元素不允许重复(指Key)。重复相当于替换Value值
  - ⭐HashMap、LinkedHashMap通过hash值确定的索引、equals比较key的结果，两者都相同才算重复
  - ⭐TreeMap若传入了一个Comparator匿名对象，就使用实现的compare方法去重和排序，如果方法返回0，则认为是相同的Key，替换Value;若没有传入Comparator匿名对象，则以添加对象实现的Compareable接口的comapareTo去重和排序，如果方法返回0，则认为是相同的Key，替换Value。
  
Map图
![](images/2022-10-10-16-25-54.png)
![](images/2022-10-08-17-37-28.png)

### ⭐HashMap
HashMap底层：
  - 底层维护的是table数组+单向链表+红黑树
  - 元素无序，不可重复，元素是双列形式Key-Value(hash值确定的索引、equals比较key的结果都相同才算重复)
  - 添加元素时先得到hash值，根据一系列算法对hash值进行处理，得到一个索引，再判断table数组该索引处有没有元素。若没有则直接添加；若已经存在元素，则调用equals比较Key，若相同则会替换Value，不相同则挂载到链表上。

HashMap内部定义：
  ``` java
  class Node<K,V> implements Map.Entry<K,V> {
  K key;
  V value;
  Node<K,V> next;
  }
  Node[] table;
  //table是HashMap里的一个数组,里面存放的是Node类型的元素。一个结点可以形成一条链表，链表到达一定条件会进行树化
  //Node是HashMap的一个内部类，里面封装了Key和Value和next指针等
```

HashMap的entrySet()方法：
  ``` java 
  /*
    一. HashMap的一部分内部类
      - class EntrySet<Map.Entry<K,V>>;
      - class Node implements Map.Entry
      - EntrySet<Map.Entry<K,V>> entrySet; 

      注意1：entrySet里面元素定义的是Entry类型，实际存放的是Node类型。本质是将table里的Node结点放入entrySet

      注意2：Entry是Map中的接口。提供了getKey()和getValue()两个重要方法获取，Node实现了该接口，也就实现了这两个方法

    二.对象名.entrySet()方法
    HashMap提供了entrySet()方法来获取集合entrySet，里面存放了Node结点，指向table中的Node结点，
      
    三.entrySet使用举例
    HashMap map = new HashMap();
    Set set = map.entrySet();//获取entrySet
    for(Object o:set){//向上转型
    Map.Entry entry = (Map.Entry)o;//向下转型
    System.out.println(o.getKey() + o.getValue());
    }
  */
  ```
   
### ⭐LinkedHashMap
LinkedhashMap底层：
  - 底层维护的是table数组+双向链表
  - 元素有序，加入顺序和取出顺序一致,因为维护的是双向链表
  - 元素不可重复(hash值确定的索引、equals比较key的结果都相同才算重复)
  - 添加元素时先得到hash值，根据一系列算法对hash值进行处理，得到一个索引，再判断table数组该索引处有没有元素。若没有则直接添加；若已经存在元素，则调用equals比较Key，若相同则会替换Value，不相同则挂载到链表上。

LinkedhashMap内部定义：
  ``` java
  class Entry<K,V> extends HashMap.Node<K,V>{
  Entry<K,V> before, after;
  K Key;
  V value;
  Entry<K,V> next;
  }
  Node[] table;
  //table是LinkedHashMap里面一个数组，定义的是Node类型，但table里面实际存放的是Entry类型的元素
  //Entry维护了befor,after形成双链表；head，tail分别指向头结点和尾结点
  ```

### ⭐Hashtable
![](images/2022-10-09-11-51-03.png)

底层数据结构是：table数组+单向链表

``` java
class Entry<K,V> implements Map.Entry<K,V>{
  K key;
  V value;
  Entry<K,V> next;
}
Entry<K,V> table
```

### ⭐Properties
![](images/2022-10-09-14-49-34.png)

适用场景：通常用于IO流读取xxx.properties配置文件信息到IO流对象中，然后通过load方法将IO流对象中的信息加载到Properties对象中，通过key获取value

### ⭐TreeMap
无参构造器->按照添加对象实现的Compareable接口的compareTo来进行排序和去重
  - 注意：若既没有传入比较器，添加的对象又没有实现Compareable接口，则会出现异常

可以向构造器传入Comparator->按照实现的compare方法来进行排序和去重
  


