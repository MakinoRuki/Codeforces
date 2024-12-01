A. 观察一下，最终结果其实只是2\*max(w)+2\*max(h)。

***B. 从前往后看，如果一个数前面没有比自己大的数就把它挑出来，这样的数组成一个非递减序列，可以发现只能保留某一种数字。但是因为开始sort之前就要删掉(设为x)，所以导致一些本来可以被x删掉的数字也删不掉了。因此枚举最终剩下的数i，在i之前的全部删掉，i之后的模拟sort过程。***

C. 每个位置i在长度为a[i]+i-1的时候可以给长度增加i-1，因此按照a[i]+i-1排序，用set模拟。

D. 可以直接dp[i,j]表示当前b中k到了i时，删掉a中前j个最小代价。先让dp[i,j]=dp[i-1,j]，然后对于i使用单调队列+双指针转移。D2找方案数，只需要加一个map记录下每个cost对应的方案数。