B. 观察一下发现两边是1，中间都是0的时候是最优的。

C. 一定只能用不在T中的k，从小到大筛法删除。

***D. 首先就是枚举最终escape在0还是n+1。然后尽量朝着一个方向走，如果走不了了(当前sum<0)就从当前方向走过的max(sum)位置往反方向走看能不能使得当前sum>=0。反方向也是走过的部分也是累积的。***

***E. 等式其实相当于对于任意r1,r2满足a[r1][j+1]-a[r1][j]!=a[r2][j+1]-a[r2][j]。因此给每行设一个不同的公差d然后直接根据b[i]构造等差数列。***
