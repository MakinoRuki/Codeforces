D. dp。

E. 首先如果存在奇数且并没全相等那就要先全部变成偶数，然后使用(2,4,6,8)某个排列作为循环节。

   这样排序后枚举最大数mx要加多少，也就是枚举mx,mx+2,mx+4,mx+6,mx+8并check其余数是否可以都变成这个值。
   
F. 根据d13+d23-d12讨论。

G. 二分每个i从root走多远，倍增法check sum。