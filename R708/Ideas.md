A. 肯定是先让小的数字出现。排个序dedup之后从小到大放。

B. 按照%m的余数分类，两两配对。

C. 考虑特殊情况。k=3根据n的奇偶，n/2的奇偶拆成(1,n/2,n/2)和(2,n/2-1,n/2-1)和(n/2,n/4,n/4)。k>3时把多余的拆成1，转成k=3。

E. dp+预处理出在i位置x步操作最远能到达的左端点j。这个可以枚举操作步数x然后slidingwindow处理出一个i对应的j在哪里。
