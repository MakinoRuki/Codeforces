A. 从大到小Alice能找到一个出现奇数次的a[i]即可。

B. [y,x]全是1，然后[1,y-1]和[x+1,n]是-1和1交替。

C. 操作一次之后就会变成[0,...0,x,x,...,x,y,...,y,z,...,z]这样的形式。然后每次再运算，每个数的出现位置就会往后推一位，直到全部变为0。可以用公式算出每个数会出现的次数。

D. 因为同样的两行只会出现一次2x2，而且只会出现在前4个黑格上。因此dp[i,0/1/2]表示前i行结束时候第i行的状态是没有2x2剩下来/有2x2但是是前2格/有2x2但是是后2格的最少操作次数。