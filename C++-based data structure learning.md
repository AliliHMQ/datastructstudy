**>> C++-based data structure learning roadmap >>**

How？想一想在物理和数学题中，解题的基础是什么？没错，就是公式！如果没掌握公式，肯定是无法解题的。而算法模板就是算法题中的基础公式

(1)Review C++ basics: pointers, dynamic memory (new/delete), classes, templates, and STL basics.

复习C++相关基础（指针、类、模板）；学习复杂度分析；实现动态数组和单向链表。

(2)Complexity Analysis:

Understand Big O notation and common complexities (O(1), O(n), O(log n), etc.).学习复杂度分析



第1周：复习C++相关基础（指针、类、模板）；学习复杂度分析；实现动态数组和单向链表。

第2-3周：完成栈、队列（包括循环队列）；用栈和队列解决简单问题（如括号匹配、层次遍历）。

第4-5周：二叉树与二叉搜索树；实现递归和非递归遍历；练习树的题目。

第6周：堆与优先队列；实现堆排序；了解平衡树（选学）。

第7-8周：图的基础；实现DFS、BFS；学习最小生成树和最短路径算法。

第9周：哈希表；实现拉链法哈希表。

第10周及以后：高级数据结构（并查集、线段树等）与大量刷题。



2026.2.28 week1:



1.Arrays

(1)A size-n array can be created in this way:

&nbsp;                    char a\[n];

(2)When writing the code, n must be known.

(3)What if n is unknown until program is runng?



2.Dynamic Allocation of Arrays



char\* a=NULL;

int n; //array size

cin >> n; // read in the size, e.g., get n = 5

a=new char\[n]; //将内存的起始地址赋给 a；

//这里输入数组a；

//When done, free memorry.

delete \[] a; 

a=NULL;



3\.C++相关基础（指针、类、模板）

大O表示法：描述算法性能随输入规模增长的趋势，忽略常数和低阶项。

时间复杂度：基本操作执行次数，分析循环、递归等。

空间复杂度：额外内存使用，分析变量、数组、递归栈等。

&nbsp;



