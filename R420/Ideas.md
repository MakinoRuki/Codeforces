C. 只会分为两部分，已经reorder过的和还没有reorder过的。reorder过的可以用set维护，没有的用list。

D. 直接求最短路，每次转移时候直接枚举k个已照明位置，但是要注意判断条件：要么相邻要么|detX|<=2/|detY|<=2。

E. 直接矩阵乘！！按照segment来矩阵乘，但是要注意上一段的result向量是可以直接作为下一段的initial向量的。
