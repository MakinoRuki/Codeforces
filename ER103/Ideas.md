A. 要么看n%k要么看k%n。

B. 一定是增加a[0]。因此二分增加多少之后O(n)来check。

C. 如果是[i,j]来组成最后结果那么就是d[i]+c[i]-d[i+1]+c[i+1]-d[i+2]+c[i+2]+...-d[j]+c[j]。因此其实是从后向前求c[i]-d[i]的最大字段和。

D. 只有LR交替才能一直走下去否则就会循环。而一开始对于第i个位置比如右边是R左边是L才能出发。

   因此dp出第i个位置向左是L最长交替序列长度和向右是R的最长交替序列长度。
   
E. 因为k<=4如果状压每个位置是不是"_"只需要16种方案。因此建图之后拓扑排序即可。
