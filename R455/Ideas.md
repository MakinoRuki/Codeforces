B. 实际就是找到区间重叠最大次数，经典问题。不同的是，并不需要处理出所有区间再来找，只要枚举每个位置计数跨着它前后的有多少线段就可以了。

C. 坑人dp。想想我们写python，都是一行一行地写，因此dp[i,j]表示第i行j个缩进的方案数。

D. 坑人暴力。把连续相同的字母计算出现次数，处理成<char,int>的pair。然后暴力模拟。。。

E. 0和1交替进行拓扑排序。
