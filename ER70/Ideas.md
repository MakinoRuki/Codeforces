A. 找y的最低位1，必须要把它移到对齐x中第一个比它高的1。

B. dp[x][y][a][b]表示用x和y从a到b最少步数，bfs。

C. 枚举插入位置和字母，维护左右上下边界最值。

D. 每次找一个最大的x满足C(x,2)<=n然后如果有w=n/C(x,2)那么就在x个3之后放w个7。
