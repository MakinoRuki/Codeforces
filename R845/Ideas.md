B. 对于某两个数(a<b)分别算出它们出现在多少排列里。

C. 排序然后2指针扫，用set维护当前因子。其实是nlog(n)的。

D. 某个顶点u在t时候之后的value其实是u的深度为t的那层儿子的xor。