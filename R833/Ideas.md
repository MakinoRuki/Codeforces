A. 找找规律，就是(n+1)/2。

B. 合法substring总长度不会超过100。

C. 改某个数i影响的是i后面的前缀和，因此从后往前看，选出现最多的前缀和去抹0，同时保存accumulate的delta。
