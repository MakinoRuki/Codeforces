A. 小的n个放前面，大的n个放后面。

B. 因为如果前n-1个当中有0隔开，那么一定要先把0填上。然后前n-1个所有的都要放到n去。

   因此就是sum{a[1], a[2], ..., a[n-1]} + cnt(0 in [1,n-1])。
   
C. 按照operation倒着模拟就好了。

D. 如果把相邻的0压缩成一个0，相邻的1压缩成一个1，那么两个串应该是相等的。

   所以对于每个s中的区间[l1,r1]要变到t中的[l2,r2]，有的需要增长有的需要缩短。因此只看增长的部分。

E. 一开始一定是把能2个合并+1的先全部处理了，这样每个数字就是0次或者1次。

   这样在增加一个数字x时，就是找到第一个比它大的出现0次的数字y，然后[x,y-1]变0，y变1；
   
   减少数字x时找打比它大的第一个出现1次的数字y，然后[x,y-1]变1，y变0。用线段树维护区间和。
