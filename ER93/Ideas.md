A. 看特殊情况。因为要求任意两边之和大于第三条边，因此看最短两边和a[0]+a[1]是否大于最大边a[n-1]即可。

D. 三种pair从大到小排序，然后dp。dp[r,g,b]表示三种分别已经取到第几对时的最大值。

E. 假如有x个lighting spell，那么要double的一定是除了最小的lighting spell的x个最大spell。

   因此维护两个set，一个存最大的x个，一个存剩下的储备spell，再来一个set存lighting spell。然后每次维护三个set。
   
   细节很多！！！
