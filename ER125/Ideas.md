A. 要移动整数距离，就先移动x再移动y。

B. 贪心，能+x就+x，不能+x就-y。

C. 两个两个的看。如果开始位置是"(",那么一定可以两个一起消；否则找到下一个")"一段一起消。

D. 类似筛法求素数，nlog(n)处理出每个type选出x个后也就是花x\c[i]的钱最多造成的伤害。

E. 条件等价于对于三角形(1,a,b)，边权(a,b)>=max((1,a),(1,b))。那么从小到大安排(1,i)的边权，然后dp。

   dp[i,j]表示前i个权cover了j个点方案数，枚举第i+1个权cover多少个点。
