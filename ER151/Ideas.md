B. 讨论BC和A的关系。

C. 直接dp，dp[i,j]表示password的第i位和database的第j位是否匹配；

然后预处理出database的j位之后下一个x字母位置nxt[j,x]，如果能找到不匹配的就存在合法解。

D. 枚举是在i结束之后的前缀和sum[i]处划线做k，如果设[i+1,n]的前缀和sum中最低值为j处，那么最终结果实际是把[i+1,n]的和整体上移了sum[i]-sum[j]也就是k-sum[j]。
