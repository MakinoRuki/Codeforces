A. l*2<=r。

B. dp[i,j]表示到第i个位置的时候，前面已经左走j次了，最大得分。

C. 剩下的要么全相等，要么长度是偶数且奇数位置都相等&偶数位置都相等。枚举奇数偶数位置的数字。

D. 对于每一个位置i来说，[l1,r1]和[l2,r2]的变化都是一样的。

   因此先变第一个位置，如果k有剩余，那么要么在第一个位置每次cost=2，要么在下一个位置cost=把两个线段连起来+延伸到[min(l1,l2),max(r1,r2)]。
   
E. 如果m月d天和d月m天满足条件，那么就是m*D+d=d*D+m(mod w) => (m-d)*D-(m-d)=0(mod w) => (m-d)*(D-1)=0(mod w)。

   因此求gcd(D-1, w)，并以此为间隔计数。
