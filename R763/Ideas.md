A. 直接模拟。

C. 二分+从后往前贪心处理之后check。

D. 找一点小case可以发现路径必然形成一个simple cycle，那么如果设起点的期望是E那么E=a[1]*(1+a[2]*(1+...+a[k]*(1+E))...)。

   其中如果第i个位置不能扫到终点则a[i]=1否则a[i]=1-p。移项求出E。