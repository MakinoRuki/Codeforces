A. 要最多个下标那么就是全选，如果全选和是偶数就好；否则去掉一个奇数。

B. 把所有restrictions中没作为b出现出现过的点作为中心点，其他点和它串起来变成一个星形。

C. dp出每个格子能到达的最左端的列，然后用线断树维护区间最小值。

D. 假如a[i]+x=a[j]+y(i<j)那么得到a[i]-a[j]=y-x。如果枚举j那么就能得到和j相邻的数字的下标。最后得到一个链再找解。

E. 其实就是贪心地随便找path。但是如果是一棵树可以使路径唯一。因此先求生成树，然后观察只要每个点degree都是偶数就可以，否则就要都补成偶数。