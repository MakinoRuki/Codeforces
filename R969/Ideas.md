A. 每次选3个连续数字。如果l是奇数就从l开始，否则就从l+1开始。

B. 首先这个操作不会改变原始数组排序后的顺序。然后每次看这个修改的区间有没有覆盖最大值max。

***C. 根据贝祖等式，每次加A或者B等价于加gcd(A,B)的整数倍。那么所有数的delta中如果是gcd的整数倍都可以被调整消除，因此所有数模gcd得到的余数才是真正的delta。但也有可能对于两个r1和r2来说，r1+gcd使得结果改变，但这时候r1+gcd必是最大值。因此枚举r中某个数为最小值，把排序后r前的r'+gcd作为最大值即可。***

D. 可以忽略中间路径上的01，只看叶子结点是1还是0。如果根节点确定，那么结果由未确定的叶子结点决定；如果根节点不确定，那么已知0/1的叶子结点不相等时先手会抢先根节点来把较多的一边变为1，而已知0/1相等时，先手不利，所以会用中间路径上的“？”来拉扯，企图让出先手。

E. 可以发现每条边其实在sum里都会被count两次。每次加入一条新边x，如果现在已经加入的总权值是y，另外的i->i+1路径上最大值必然是w-y。那么所有未完全确定的i->i+1路径都要加一个w-y。于是并查集维护哪些路径还未确定，每次合并u->p[u]时，只要看u的子树中min和max跟min-1和max+1是否可以联通。

***F. 需要知道本题的两个性质：1）每一段拿出来调整之后相邻数的delta必然都是奇数，2）每一段调整之后相邻数的delta必然都相等(否则可以通过取平均调整到相等)。那么这个相等的最终delta其实就是最开始的相邻delta们的gcd。这时还要知道一个general的性质：数组排不排序，这个相邻数delta们的gcd不改变。那么最终这个delta就必须是2的power，因为可以拆成1。因此枚举右端点，找到最靠右的第一个使得gcd为2的power的位置。可以两指针维护+线段树区间查询gcd。***
