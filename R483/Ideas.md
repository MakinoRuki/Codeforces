A. 先使gcd(p,q)=1，然后p/q能写成b进制分数，也就意味着p/q=(some integer)/(b^k) ==> q | (p*(b^k)) ==> q|(b^k)。
  
   <b> 那么不断地求出g=gcd(q,b)，然后只要q%g==0,就q/=g。</b>
   
B. 可以发现XOR(l,r)=XOR(l,r-1)^XOR(l+1,r)。那么dp[l,r]求出[l,r]上所有subsegment的最大值。

C. dp[x,st{v1,v2,v3,v4},l]表示当前上了x个人，电梯里的人要去的楼层状态是st{v1,v2,v3,v4}，当前停在l层的最小代价。

   预处理状态编号，最多只有715个。然后直接spfa。
