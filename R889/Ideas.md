***B. 有个结论是[x+1,x+r-l+1]区间内的数字必然包含[1,r-l+1]的倍数。因此可以从1作为起点开始看，根据素因子个数判断长度不会超过100，实际不会超过50。***

***C. 如果全部是非负数/非正数就会非常简单。对于正负混合的情况，可以用绝对值最大的数字去统一符号。但是如果是31次操作之内，需要会估算复杂度。***

***假设把正数变成绝对值最大需要x1步，负数需要x2步，那么一个为0另一个不超过5；改变所有负数y1步，改变所有正数y2步，y1+y2=20。所以min(x1+y1,x2+y2)<=25/2=12。***

***D. 首先如果解锁了前x张，那么总代价是确定的，就是sun[x]-(x-1)。因此只需要dp出哪些张数是可能的。用bitset记录状态，dp[i]={s}表示能到前i张的有哪些可能的总张数。但i转移完之后如果i也在状态里，要删去。***
