A. 由于gcd(x+d,y+d)必然整除max(x,y)-min(x,y),所以可以令d=-min(x,y)%(max(x,y)-min(x,y))。

B. 两个串奇偶性相反的位置必然是联通的，看这里面是否可以凑够0。

C. 一定是让最大值尽可能地去吸收掉别的数。基本就是要去掉"奇数个数-1"个1。

D. 因为每次一定可以操作使得两种字符同时增加。所以假设三种字符数x，y，z满足x>=y>=z，那么可以先同时提高y和z，使得x和z相等。这时y比它们都大，再同时提高z和x达到和y相等。

**E. 一个有意思的观察是，(1,1)出发四个边界上转一圈回到(1,1)，黑白变色一定是偶数次。因此不改变结果的奇偶性。对于中间的位置，因为相邻4个格子同色和异色的一定是同奇同偶，因此反转不影响结果，那么可以全涂白色。就只要看中间各子和边界相邻，边界能有多少黑格子。答案要么是2^(nm-k)要么是2^(nm-k-1)。**
