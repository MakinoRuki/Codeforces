B. 要么就是剩下左边一部分，要么剩下右边一部分，要么两边都剩下一部分，但这时候左右两端必须相等。

C. 正n多边形上3个点组成的角abc的计算方法，从b的角度看过去，就是b所在的那个内角的一部分。

D. dp。dp[i,j1,j2,j3]表示到第i个位置当前是否有"h","ha","har"的最小cost。

F. 看每个位置的贡献。假设在p中出现了的数集合是S，未出现的集合是P。那么看第i个位置，对于j>i的S中的数字就是P中大于它的数字个数，对于j<i的S中的数就是P中小于它的数字个数。

   从右往左扫一遍，BIT维护。