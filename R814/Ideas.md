A. 首先如果选两个区间一个完全包含另一个不可能，因为一定可以拆开变成更优。然后再看交叉区间其实交叉的位置不会超过1个。再仔细考察可以拆成长度为2个/1个最优。

   2个的情况时如果两位置ab不相等，那么相当于给b异或a然后往后传，直到到一个z的位置，使得z的值等于从a开始所有数的xor。因此[a,z]的xor为0。
   
   因此dp[i]表示以i为结尾的最优解，然后要么从dp[i-1]转移而来要么从前面某个xor相等的位置转移而来。

***B. 因为实际用到的fibonacci项数不会超过60。因此可以贪心，对每一项优先使用当前所剩c[i]最大值。因为如果不是最大值拿来用，那么它会用来凑前面更小项的和，就可能用不完。***
