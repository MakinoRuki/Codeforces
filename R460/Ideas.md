B. 打打表看一看，发现这个第k个这样的数并不会很大。因此枚举就可以了。

C. 要注意讨论n=1,m=1的情况。

D. 先判环。然后枚举每个字母，记忆化dp。

E. 快速幂+费马小定理+中国剩余定理。

   先利用费马小定理，(a^n)%p => (a^(n%(p-1))%p。枚举n%(p-1)=r1, 然后推算出n%p=r2。
   
   得到模同余线性方程组，解出一个模p*(p-1)的解之后算出[1,x]之间解的个数。
