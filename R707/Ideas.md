A. 先考虑特殊情况，4个全相等或者存在2对两两相等的；否则直接暴力枚举i和j看sum[a[i]+a[j]]的上次出现两个坐标是否和i，j相等。

B. 二分 + 模数不互素的CRT。