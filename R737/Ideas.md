B. 排个序然后从小到大看下标是否连续，确定最少分成多少段x，看x<=k。

C. 从高到低按位看，根据AND(a1,...,an)>=XOR(a1,...,an)确定每一位的方案数。

D. 线段树dp。把连续的1线段离散化，然后线段树维护当前row所cover到的区间的最大值。