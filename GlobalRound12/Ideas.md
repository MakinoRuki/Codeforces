B. 要么就是一步把所有点缩到一起，要么就是缩不起来。

C. 操作不超过k/3次，那么应该需要按照某个标准把所有的token分成3类。一个想法就是按照模3划分，只是i或者j模3都不行，因此是(i+j)%3。

D. 先看最小值，如果出现在中间或者出现次数>1，那必然k>=2都不符合，因此1必然出现且只出现在某一端。那么去掉1之后再看剩下的n-1个数字，以此类推。

   一旦剩下x个数的时候不符合了，那么合法的k就是k>=x。对于n和1特判。