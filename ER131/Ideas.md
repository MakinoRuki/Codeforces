B. 用最小的2乘的power一定是最多的，但是每个能乘2的数都要乘。

C. 二分最后答案时间，然后每个worker优先处理他擅长的用时1，然后剩下的都是2再看哪个worker还能处理。

D. 如果i/a[i]=b[i],那么a[i]的范围是[i/(b[i]+1)+1, i/b[i]]。

   按照区间右端点从小到大其次左端点从小到大排序，然后贪心。贪心时候在set里维护还可以用的数字然后在set里二分。
