A. 关键是看翻转的这一段里面01的情况。

   假设翻转区间[l,r]，那么我们翻转之后以原来的位置i作为1和2的分界位置，列个式子可以发现就是找i-2*s[i]最小。s[i]是i之前1的sum。
   
B. 多项式除法+把n转成-k进制。