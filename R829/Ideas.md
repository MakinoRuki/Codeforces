C2. 首先绝对值是1的数一定是偶数个，然后两两配对即可。

***D. 用到一个结论，1!+2!+...+n!<(n+1)!，那么如果x!出现了cnt次，从cnt中扣掉x+1，加到(x+1)!的次数中去，从小到大操作过一遍如果[1,...,x-1]阶乘还有剩余则不能整除。***

E. 设共有x个0，dp[i]表示前x个位置有i个1需要移动到后面去的期望步数。那么dp[0]=0,dp[i]=P\*(dp[i-1]+1)+(1-P)\*(dp[i]+1)=>dp[i]=dp[i-1]+1/P。
