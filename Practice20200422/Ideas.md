559B. reflexively, simmetrically, transitively的关系叫全等关系，可以将set分成不相交的partition。因此把s和t都变成全等的最小字典序string。

1114D. dp。从i到j最后的颜色要么是i开始的一段，要么是j结束的一段。

607B. dp。回文串就看两个端点，相等则dp[i][j]=dp[i+1][j-1]，不相等则枚举中间从哪拆开。
