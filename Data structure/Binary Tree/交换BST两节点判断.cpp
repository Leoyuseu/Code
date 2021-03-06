题目一
一棵二叉树原本是搜索二叉树,但是其中有两个节点调换了位置，
使得这棵二叉树不再是搜索二叉树，请找到这两个错误节点并返回。
已知二叉树中所有节点的值都不一样，给定二叉树的头节点 head，
返回一个长度为2的二叉树节点类型的数组errs，errs[0]表示一个错误节点，
errs[1]表示另一个错误节点。
进阶：如果在原问题中得到了这两个错误节点,我们当然可以通过交换两个节点的节 
点值的方式让整棵二叉树重新成为搜索二叉树。但现在要求你不能这么做,而是在结构上 
完全交换两个节点的位置,请实现调整的函数。

题目二
判断一个数是否是回文数，定义回文数的概念如下：
1，如果一个非负数左右完全对应，则该数是回文数，例如：121，22 等。
2，如果一个负数的绝对值左右完全对应，也是回文数，例如：-121，-22 等。
给定一个32位整数num，判断num是否是回文数。


题目三
正数数组的最小不可组成和
【题目】
给定一个正数数组arr，其中所有的值都为整数，以下是最小不可组成和的概念：
1，把arr 每个子集内的所有元素加起来会出现很多值，其中最小的记为min，最大的为max。
2，在区间[min,max]上，如果有数不可以被arr 某一个子集相加得到，那么其中最小的数是arr的最小不可组成和。
3，在区间[min,max]上，如果所有的数都可以被arr的某一个子集相加得到，那么max+1是arr的最小不可组成和。
请写函数返回正数数组arr的最小不可组成和。
【进阶题目】
如果已知正数数组arr中肯定有1这个数，是否能更快地得到最小不可组成和？