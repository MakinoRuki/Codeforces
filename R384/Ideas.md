A. 如果ab同色就是0，不同色必然有01分界的位置因此是1。

C. 其实就是找1/x+1/y=1/n => 1/y=1/n-1/x => 1/(n*(n+1))=1/n-1/(n+1)。

D. 其实等同于在任一个顶点的子树中找最大和次大的两个儿子。

E. 二分出现次数+状态压缩已经选了那些数，dp[s]表示集合s的最小最后出现位置，然后枚举下一个数字找到最近结束位置。
