A. AND这个操作z一定是越来越小的，因此直接z和其他所有数求OR的最大值。

B. 答案不会超过2。

C. 对于a中数字x=m^p * y，全部拆成m^p个y然后合并，然后再看b中是否能对应上。

D. 找到1和n的下标x和y之后，x和y必然连边。然后1的一侧不断交替找最大值->最小值->最大值...一直到端点，n的一侧最小值->最大值->最小值...直到端点，同理。

E. 可以发现只要找到每个白点被touch到了多少次。然后这个次数就是路径条数。
