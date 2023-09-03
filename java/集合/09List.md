### List
List特性
  - List集合中元素是有序的（即添加和取出顺序一致）
  - 元素可重复
  - List集合中每个元素都有其对应的顺序索引，即支持索引 


Collection图
![](images/2022-10-10-10-37-11.png)


### ⭐ArrayList和Vector
注意：
  - ArrayList底层是由数组实现数据存储的
  - ArrayList基本等同于Vector，除了ArrayList是线程不安全的(执行效率高)，多线程情况下不建议使用ArrayList

ArrayList扩容机制：
  - ArrayList底层维护了一个Object类型的elementData数组，transient Object[] elementData。transient表示该属性不会被序列化
  - 当使用无参构造器创建ArrayList对象时，elementData容量为0，第一次添加时，扩容为10；如需再次扩容，扩容为1.5倍
  - 如果使用指定大小的构造器，则初始elementData大小为指定值，如果需要扩容则直接扩容为1.5倍

Vector扩容机制：
  - Vector实现了线程同步synchronized，是线程安全的
  - 当使用无参构造器创建Vector对象时,elementData默认容量为10，以后每次扩容为2倍
  - 如果使用指定大小的构造器，则初始elementData大小为指定值，如果需要扩容则直接扩容为2倍

Vector和ArrayList底层比较：
![](images/2022-10-06-19-26-44.png)



#### ⭐LinkedList
LinkedList底层：
![](images/2022-10-06-19-49-55.png)
说明：Node节点是LinkedList的一个内部类

ArrayList和LinkedList的比较和选择：
![](images/2022-10-06-20-44-02.png)

