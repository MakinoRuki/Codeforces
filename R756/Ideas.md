B. min(min(a,b), (a+b)/4)。

D. bfs。

E. 每个人所在位置为p[i]，因为V是从1出发，因此这个人要去拦他必然最优位置是p[i]到root(1)的路径中点。

   按照到根结点距离的从小到大去安排这些人，每个人都到他该去的位置后，dfs检查碰到的那些人就是一个minimum set。
   
F. 枚举左起点找到一个最远的右端点。当左端点往右推进的时候只有右节点变大才会更优，变小的可以不管。