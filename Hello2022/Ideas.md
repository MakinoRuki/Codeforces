A. k<(n+1)/2才有解。

B. 维护最小l和最大r的最小cost，再维护包含[minl,maxr]的最小cost。

C. 会发现每个位置会连续出现它在原排列p中所在置换的每个数字。因此就一直query一个位置，直到得到这个置换。

D. 会发现有8个角是必须空出来的：a[0,n],a[0,2n-1],a[n-1,n],a[n-1,2n-1],a[n,0],a[n,n-1],a[2n-1,0],a[2n-1,n-1]。

