A. 找找规律，就是(n+1)/2。

B. 合法substring总长度不会超过100。

C. 改某个数i影响的是i后面的前缀和，因此从后往前看，选出现最多的前缀和去抹0，同时保存accumulate的delta。

***D. 因为要能被d整除，因此设d的二进制最低位为k，那么a|b不能有比k低的位。那么不妨找一个x使得x包含a|b所有的位，也就是直接让30位中k之上的全为1，然后k以下为0。得到x=(p・2^(30-k)+2^(30-k)-1)・2^k。推一下可得p的表达式。需要用到的知识是：a=(1/2)^b(%k) ==> a=(1/2)^b・(k+1)^b(%k) ==> a=((k+1)/2)^b(%k)。***
