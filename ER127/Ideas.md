C. 随着天数增长，能买到的最后一个位置是递减的。从后往前看每个位置最多能买到第x天，那么就能被选x+1次。

D. 其实只取决于1和x要插在哪。枚举1和x插在哪里得到增加的最小delta，但是注意1和x可能插在同一个缝隙里。

E. 从低往上dp，u这个子树方案数取决于左右儿子方案数相乘再看能不能翻转。而判断翻转可以直接暴力记录左右儿子string，这个其实是n\*log(n)复杂度。