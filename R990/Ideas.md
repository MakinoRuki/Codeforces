C. 除了有一个col需要上下都用，其余要么用上，要么用下，因此直接dp，dp[i,j,0/1]表示i个用上j个用下以及有没有上下全用的col的最大cost。

D. 从左到右扫一遍，维护单调递增队列，每个位置最多被踢掉一次，因此用个小根队维护被踢掉的元素(with +1)，然后重新加入队列。
