C. 考虑特殊位置。要么删掉根(v=1)，那么剩下的dfs模拟即可；要么不删(v=1)，那么剩下每条路径上的gcd最终都是a[1]的因子，因此根下枚举然后模拟。

D. 这也是从特殊情况开始想起。要么当前需要去异或的x跟a中任何数字不想等，那么异或之后没有0，答案就是mex=0；要么x跟a中某个数字相等，因此可以预处理某个a[i]跟a中其它数字异或结果的mex。

   把a中数字建成01trie树；那么从高到低看a[i]的每一位b，如果跟a[i]这一位相等的数字已经有(1<<b)个，那么mex的这一位一定是1；否则是0。根据这个决定往trie树的哪边儿子走。
