C. 要么给某数+1，要么add一个最大数字；最优解一定是先把1加到x，然后再重复copy这个x。那么也就是说要最小化{x-1+n/x-1}，那么x到sqrt(n)时是最小。

D. 从前到后维护prefix_sum的set，出现重复了就清空set，从重复位置i的前一个位置prefix_sum(i-1)开始重新插起。

E. 最小值暴力枚举所有对战情况。

F. 这题有奇怪的dp做法。但我是枚举中间“b”的位置，然后看左边是选"a"还是选"?"，然后右边是选"c"还是选"?"来组合计数。