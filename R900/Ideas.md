B. 直接构造，从2开始，后一个数等于前一个数+1，如果check不符合条件就再+1。

F. 因为d(n)始终<=10^9，因此素因子个数不超过30，用map维护每个素因子的个数。然后type2的query时候只需要比较因子个数和和n之间每个素因子的次幂大小。

***G. 因为是OR操作，所以当从x到y的枚举z时，bit改变不会超过30次，且最大值的z只会在bit改变时产生。因此求出xy的LCA之后，枚举x某一位i改变时的z，然后倍增法求出g(x,z),g(z,lca),g(y,lca)。因为z可能跨过lca，因此从y也枚举一遍。***
