A. 如果n是偶数那么n/2是偶数结果就是0否则是1，n是奇数把1，2，3单独拿出来，剩下的(n-3)/2是偶数就是0否则就是1。

C. 取决于x和y的大小关系，x>y那么最后全为0，x<=y那么一步可以减到0的位置只能取得一半。

E. b[1]=0,那么所有和a[1]相等的位置都是0，那么和被这些位置覆盖的区间中的a[i]相等的更多的b中位置也要是0，以此类推，类似扩展相交区间。

   假设有x段那么答案就是2^(x-1)。
   
F. dp[i,i1,i2]表示哪些行已经被选进去了，第一行是i1,当前行是i2的最少cost。
