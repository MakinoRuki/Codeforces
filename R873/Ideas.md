B. 算出每个需要对齐的i和p[i]之间的距离dt，k必须要整除每个dt，因此求这些dt的gcd。

C. a和b都从大到小看，到i为止，a中大于b[i]的有x个，现在已经使用了n-i个，那么i处的选择有x-(n-i)。

D1. 本质上就是求区间并。枚举左端点，往右扫的时候维护stack，栈中每个元素(mx,cost)是前面一段最大值和花费代价。
