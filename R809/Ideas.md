B. 找规律发现相同数字间隔奇数个就能叠到一起，因此对每个数字分开看。

C. 最多的building就是间隔1个位置选一次。但如果n是偶数就需要特殊dp一下。

D1. 枚举最小值，然后对每个位置二分超过这个最小值的最小数，在所有n个里面取max。