C. 每次操作完，一定是fixed point在最后，只要模拟找出这些fixed point就可。

D. 首先b一定是倒序插入，然后对每个b[i]要在a中找到第一个比它小的j，把b[i]插在a[j]前面。

E. 最后的len如果不是任何一个a[i],那么所有L的total和所有R的total组成的区间[totl,totr]中必然存在一个a[i]排序后不存在的数；否则就枚举a[i]，然后不包含a[i]的set里尽量多选，包含a[i]的set里尽量少选。预处理出al,ar,an三个set表示包含某个a[i]的所有l/不包含某个a[i]的所有r/包含某个a[i]的set要达到l需要选上至少多少个a[i]。
