A. 15的倍数+0，1，2。

B. 模拟找出第一次回到0要q步，第二次回到0要r步，那么就是q+r\*k。

C. 因为看的是最大penalty最小，因此二分。然后扫一遍，不超过二分的值就跟前面的同色就好了，否则必须改成对应颜色。

D. 从底层到上层，按层算，到节点u的总方案数。

**E. 对于后手来说一定是先拿01最优。而其实先手每次拿00是否相邻其实也无所谓。考虑后手什么时候会输，要么是1全拿完了而先手还有0可以拿，要么是还剩一个1但是没有0可以匹配了。根据这些推出n0和n1的关系，要么是n0>=3n1+2，要么是n0=3n1-1。对于区间[l,r],n0=sr0-sl0,n1=sr1-sl1。因此可以BIT维护。再来看为什么00可以不相邻因为如果n0个数足够多，可以假设先把1摆满然后把0按照1:3插进去，如果某个空里0减少，其他空里必会增多。**
