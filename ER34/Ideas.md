B. 要HEAL肯定是开始就HEAL，枚举多少次。

C. 贪心，从小到大每个box能塞就塞。

D. 排序然后BIT，但是会爆long long和double，因此要用long double...

E. 枚举第一个串swap哪两个位置，然后其余s个跟第一个s最多diff四个位置加上枚举的2个位置共6个。

   只需要看这6个位置是否满足，不过check时候注意去重。
