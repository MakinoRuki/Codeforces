B. 至少保留某一位全是1的。枚举看哪一位。

C. 有两个观察，当偶数次就是交换1和0的位置，奇数次就是除某个1之外的01翻转；

   奇数次时这个多出来的1次可以在任何时候发生不影响结果，因此就上来枚举先以哪个1不动翻转其他位置，然后看01和10对是否相等。bit
   
D. 首先看出结论bit_count(x^y)%2 == (bit_count(x)%2) ^ (bit_count(y)%2)；或者直接猜每条边0/1就足够了。

   关键的处理是，这么多(a,b)对，其实只要转化成(root,a)&(root,b)就可以了。
   
   因此只要根据(a,b)=0/1连边，然后已有的边也根据bit_count(edge)的奇偶给(u,v)连边，然后dfs给联通块确定值，剩下的给0。那么val(u,v)=dp(u)^dp(v)。