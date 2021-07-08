A. g=gcd(a+x, b+x) => g|(a+x),g|(b+x) => g|(a-b). a=b(mod(a-b)),所以把ab都变成min(r,(a-b)-r)。

B. 每个数之间差值尽量小，因此尽量均分。

C. 没办法表示状态且很快收敛，所以说直接dfs。

D1.n次query去找出[0,n)范围内的数字，因此要每个query确定一个数字。从0开始，每次query的是i^(i-1)。

   本质上就是要每次query不仅能确定当前数字是不是答案，而且能消除上次query的影响。
   
D2.假设query了a1,那么x的个位数字就变成了(a1-x)%k。因此下次query就变成(a1-a2)%k，然后x变成(x-a2)%k。

   因此再下次query的是(a3-a2)%k。因此奇偶交替。
