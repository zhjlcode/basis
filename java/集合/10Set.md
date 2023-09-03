### Set
Set特性
  - HashSet无序，LinkedHashSet有序，TreeSet可排序
  - 元素不允许重复(指Key)，重复则放弃添加
    - ⭐HashSet、LinkedHashSet通过hash值确定的索引、equals比较key的结果，两者都相同才算重复
    - ⭐TreeSet若传入了一个Comparator匿名对象，就使用实现的compare方法去重和排序，如果方法返回0，则认为是相同的元素，就不添加;若没有传入Comparator匿名对象，则以添加对象实现的Compareable接口的comapareTo去重和排序，如果方法返回0，则认为是相同的元素，就不添加。

HashSet、HashMap和LinkedHashSet、LinkedHashMap四者之间的关系
  - HashSet底层实际是HashMap
  - LinkedHashSet底层实际是LinkedHashMap
  - LinkedHashSet是HashSet子类，LinkedHashMap是HashMap子类，

Collection图
![](images/2022-10-10-10-37-11.png)

### ⭐HashSet
![HashSet](images/2022-10-07-16-43-56.png)

HashSet底层：
  - ==HashSet底层实际上是HashMap(table数组+单向链表+红黑树)==，使用HashMap的Key保存元素，Value被常量填充
  - 元素无序，不可重复(hash值确定的索引、equals比较key的结果都相同才算重复)
  - 添加元素时先得到hash值，根据一系列算法对hash值进行处理，得到一个索引，再判断table数组该索引处有没有元素。若没有则直接添加；若已经存在元素，则调用equals比较Key，若相同则放弃添加，不相同则挂载到链表上。

HashMap内部定义：
  ``` java
  class Node<K,V> implements Map.Entry<K,V> {
  K key;
  V value;
  Node<K,V> next;
  }
  Node[] table;
  //table是HashMap里的一个数组,里面存放的是Node类型的元素。一个结点可以形成一条链表，链表到达一定条件会进行树化
  //Node是HashMap的一个内部类，里面封装了Key和Value和next指针等。HashSet使用Key保存数据，Value则被HashMap的一个公共常量对象PRESENT填充。
  ```

HashSet扩容机制(即HashMap扩容机制)。
注意：jdk8以前是数组+单向链表,jdk8以后添加了红黑树
![HashSet扩容机制](images/2022-10-07-18-53-26.png)
链表树化过程：
   - 链表阈值为8。
   - 第一次添加时，table扩容到16，table数组临界值为12(数组大小的0.75倍)
   - 继续添加元素。若table实际占用空间达到临界值12则直接按数组扩容；若没达到临界值12，但是向链表元素个数>=8的链表中添加元素，则table扩容至32，临界值为24
   - 继续添加元素。若table实际占用空间达到临界值24则直接按数组扩容；若没达到临界值24，但是向链表元素个数>=8的链表中添加元素,则table扩容至64，临界值为48
   - 此时table大小为64，如果有链表元素个数>=8，则该链表达到树化(红黑树)条件。若继续向达到阈值的链表中添加元素，则该链表会进行树化(树化是针对链表而言的)
   - 总结：只有当table大小达到64并且向达到阈值的链表中继续添加元素，这条链表才会进行树化。否则添加元素时仍按照数组扩容机制

### ⭐LinkedHashSet
![LinkedHashSet](images/2022-10-07-19-38-29.png)

LinkedHashSet底层：
  - LinkedHashSet底层实际是LinkedHashMap(table数组+双向链表)，使用LinkedHashMap的Key保存元素，Value被常量填充
  - 元素有序，加入顺序和取出顺序一致,因为维护的是双向链表
  - 元素不可重复(hash值确定的索引、equals比较key的结果都相同才算重复)
  - 添加元素时先得到hash值，根据一系列算法对hash值进行处理，得到一个索引，再判断table数组该索引处有没有元素。若没有则直接添加；若已经存在元素，则调用equals比较Key，若相同则放弃添加，不相同则挂载到链表上。

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
    //Entry维护了befor,after形成双链表；head，tail分别指向头结点和尾结点；LinkedHashSet使用K保存数据，V被公共常量对象填充
    ```

### ⭐TreeSet
TreeSet底层实际是TreeMap

无参构造器->按照添加对象实现的Compareable接口的compareTo来进行排序和去重
  - 注意：若既没有传入比较器，添加的对象又没有实现Compareable接口，则会出现异常

可以向构造器传入Comparator->按照实现的compare方法来进行排序和去重
   

  

