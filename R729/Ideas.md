B. 考察n需要满足的形式，必然是a^x + k*b。

C. 从小到大看能否被(2,3,4,5,6,7…)整除的i的个数，其实也就是(2,3,2,5,7,...)。拆解之后一直到47就够了。

   每个i要么在某个数处被剔除，要么包含所有这些素因子，那么这些素因子不会超过50个。

D. 看每个数字的贡献。枚举”+”的位置x，dp[i,j,0/1]表示前i个数字中小于等于x的”+”和”-”的delta是j且x选没选上的方案数。

   处理重复数字经典技巧：把x作为这些duplicate中第一个选的位置。
