A. 找特殊情况，x=-u*u,y=v*v。

B. 枚举左右切分，左边按照列分割右边按照行分割；然后再上下切分，上面按列下面按行。

C. a和b都从小到大排序，然后从大到小贪心。

D. 只能二分。先二分出i的位置，然后查询(i+2,n)得到的结果会比(i,n)的少(j-i)！！

E. 对于一个起点为l来说，满足条件的r需要是a[l]-a[l+1]<=0,a[l]-a[l+1]+a[l+2]>=0,a[l]-a[l+1]+a[l+2]-a[l+3]<=0,...,a[l]-a[l+1]+a[l+2]...+/-a[r]=0。

   因此按照奇偶下标分开维护sum[i] = a[i]-a[i-1]+a[i-2]+...+/-a[1]的单调递增队列，枚举l然后二分出两个最右边界确定最终边界，然后找这个区间内多少sum[i]-sum[l-1]=0。
   
   这个问题是经典套路，只要用map记录所有位置然后二分。