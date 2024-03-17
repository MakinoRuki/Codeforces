B. 分情况：1)m%n==0; 2)m%n!=0,n%2!=0; 3)r=m%n,r!=0,n%2=0,r%2=0; 4)r=m%n,r!=0,n%2=0,r%2!=0，这种情况无解。

C. 用stack维护sum。sum=0的subsegment是一个component，但如果遇到两个相邻的sum=0的component，可以合并。

***D. 对于m=n-1来说因为每删一条边增加一个component，所以是固定n+1个component。然后对m=n,n+1,n+2的情况同样讨论，发现最优解都是2\*n-m个，需要满足的条件就是每个环上都有红蓝两色。可以先找生成树涂成R，剩下的B。如果有环则调整。***
