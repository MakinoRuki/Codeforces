B. 重要的是a[j]<=a[i]而不是j<=i。因此就按照a[i]从小到大排序，对于一个i，它的上下边界用两指针扫出来。注意最后特判一下相等(a[i]==a[j])的情况。

C. 数字范围1->70，因此把数组a压缩成不超过70个元素。dp[i,j]表示i个数选出素因子是奇数个数的状态是j的方案数。然后每个数字只看选奇数个偶数个就可以了。

D. 找到第一个a[i]<b[i]的位置。如果要在[i+1,n-1]的位置增大a的字母，那么其后面的字母随便排列；如果要在第i位增大，增大之后仍然小于a[i]那么之后也是随意；

   如果增大到b[i]，那么就是枚举一直跟b相等，直到某一位i'小于b[i']。因此处理出a1[i]表示第一个大于a的位置在i之后的方案数；处理出b1[i]表示第一个小于b的位置在i之后方案数。
   
   注意这里算“其后tot个位置字母随便排列”的方案数时，可以用tot/((cnt[0]!)*...(cnt[25]!))。
