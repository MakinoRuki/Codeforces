B. 奇怪的构造题。k偶数就两两放在二三行同一列；然后因为列数是奇数，所以k奇数就现在中间列第二行放一个，再然后关于中间列两两对称放在第二行，第三行，然后列往两边扩。

C. dp。字典序最小就是从前往后处理；对于每个位置尽量向左扩展到它能扩展到的最小值；dp[i]记下i位置能往左扩展到的最小的数。

D. 完全平方数！需要看素因子幂次是奇数还是偶数的时候！先把所有素数的平方项除掉！又因为至少是p^2才要去处理，所以只需要筛出sqrt(n)以内的素数就好了！

E. 从小到大删好像不太对；那么就从大到小保留。首先n一定要保留；然后从大到小枚举i，找到i距离保留的节点set最近的位置(就是i在set中的父亲)，这个可以用倍增法处理。

   这样的正确性是因为a[i]=2^i，那么比i小的所有a[j]加到一起也不会超过a[i]。
