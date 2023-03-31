A. 相对位置不会改变，两堆连起来，相邻相同的最多只有一对位置。

B. 只保留k所在的线段。

C. 需要看每个a[i]能完整cover到几个taster，那么产生一些区间[l,r]以及一些吃剩的delta。

   delta部分特别加上，产生的区间排序，对每个taster扫描看多少区间cover了他。
   
D. 想要总weights尽量大，应该是全部三角形分成n/6个RRB和n/6个BBR。对每个三角形讨论怎么选能weights最大。
