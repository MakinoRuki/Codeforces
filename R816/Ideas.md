A. 必然是第一个人全走，第二个人全走行传送列or全走列传送行。

***C.用dp来算贡献。sum[i]表示以i结尾所有子区间的g值和，那么如果a[i]=a[i-1]则sum[i]+1,否则sum[i]+i。然后dp[i]表示总代价，dp[i]=dp[i-1]+sum[i]。修改a[x]时因为x和x-1会有影响和x+1也会有影响，因此两侧分别讨论，相等变不等和不等变相等的delta。*** 

D. 按位看。x=0时两边都标为0，然后要字典序最小就从左到右看每个位置是否能是0。这时候只有在x=1然后另一边已经是0时才必须为1。
