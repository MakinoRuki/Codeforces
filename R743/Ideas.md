B. 先把b中每个数字移到开头的步数算出来，排序，对于a中数字枚举然后在b中二分。

C. 拓扑排序+dp。根据i和j的页标大小关系决定是用dp[j]+1还是dp[j]更新dp[i]。

D. 如果有一段连续的1长度为奇数必须要先变成偶数才能消掉，所以一旦遇到就先把它们后面的0变成1；

   如果0长度为偶数就跟下一段1合并，长度为奇数必然最后剩下"101"的pattern那么就把这个"101"->"000"，当前这段1变成偶数长度，把下一段1奇偶性改变再往后看。