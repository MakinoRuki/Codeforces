A. lcm最多等于gcd多乘个2或者3。

B. 找一行，每隔k个位置放个X，然后其他行等于这行每次旋转一个格子。

C. 不能存在某个a[i]!=b[i]且b[i]-b[i+1]>1。

***D. 要改变结果必然是选中某个人然后一路保TA获胜，因此修改的都是这个人到根结点路径上的结果。那么从根下来每个分叉都可以选择改或者不改，因此如果改i次就是C(n,i)。i从0->k。***
