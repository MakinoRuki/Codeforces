A. 必然会是一个环，在环上循环递增。找到全局第一个最小值，看它能不能单增n个数。

B. 最小数必须为选中的2数之一，除去它的倍数，剩下所有数当中最小值(剩下所有数的gcd的因子)也要被选中。

C. 如果可以得到2个数或3个数的中位数，就可以把整个数组都变成这同一个数。因此枚举所有相邻2个数的区间和所有3个数的区间，找出max。

***D. 最优解必然是两者现在连线中点相遇，然后以相遇点为根dfs，Blue跟着Red，答案必然是2(n-1)-max{path}。***
