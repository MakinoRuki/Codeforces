A. p[i]->p[j]的数字OR起来的结果>=j-i+1，那么就直接从n到1放。

B. 中间的位置最终一定会走到右边界和下边界，所以右边界一定要全部向下走，下边界一定要全部向右走。

C. 首先我们可以发现如果p[i]的左右都有比它大的数，那么一定会存在环。所以从小到大看，一定是放在两端的位置；所以答案是n!-2^(n-1)。

D. 首先如果n>=4&&m>=4那么一定无解；而如果某一维<4则我们可以使用状压dp。
