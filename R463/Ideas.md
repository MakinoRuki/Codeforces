B. 预处理出来f[n,x]表示从1到n为止g[i]=x的i有多少个。

C(WA). 整理一下题意其实最终是求A*x + B*y = N。其实不用扩展gcd，只要枚举x是多少就可以了。

D. 很明显需要维护dp[n,p]表示n往上递增2^p的点是哪个。然后每次query的时候log(n)步找到sum满足的位置。

   而对于v如何找到第一个w[u]>=w[v]，只需要利用par[v]的dp[par[v],p]找。