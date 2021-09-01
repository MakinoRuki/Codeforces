A. 可以发现对每一位来说，只要有一个数字在这位上是0那么就能使结果为0，否则必然是1。因此所有数AND即可。

C. 要么是从中间某个i->n+1->i+1,要么就是n->1->...->n-1要么就是n+1->1->...->n。

D1. 最后必然是会把连通分量少的森林连成一棵树。因此枚举任意一对(i,j)只要(i,j)在两边都不连通就可以连边。

E. 容斥原理处理gcd=1。枚举gcd，然后看是减去还是加上此gcd的结果。根据l[i],r[i]处理出第i个数可选gcd个数的范围是[L,R]，处理一下变成[0,R-L]。

   那么问题变成背包，n个数每个范围[0,R[i]]，总数不超过m/gcd。背包dp时候注意是一个个累加但是可能会累加个数超过上限R[i],那么就需要减去。
   
   假设对于i-1得到的所有可能个数j的集合满足j+R[i]+1<=m/gcd，那么这个j就没有资格累加到i的结果中。因此要在dp[i,j+R[i]+1]提前去掉dp[i-1,j]。