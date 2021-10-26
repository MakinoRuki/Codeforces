B. 最多操作n次之后该合并之后不变的数字都不变了。

C. 每个位上独立。每个位上1的个数的gcd分解因子找出可能的k。

D. 做法一：倒着bfs，根据x+b[x]更新x所在的[y-a[y], y]，用set去掉已经放进queue的；

   做法二：从n开始bfs到0，跳到的位置为[x-a[x], upperlimit]其中upperlimit是上次跳到的位置。
