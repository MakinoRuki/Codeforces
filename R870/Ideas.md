A. 枚举几个人说谎了然后暴力check。

B. a[i]和a[n+1-i]模x之后要同余，那么也就是x需要是所有abs(a[i]-a[n+1-i])的gcd。

C. 找n最大的不超过m的因子。

D. 显然在保证三个最大值的时候区间长度越小越好，如果设两端的元素为bl和br，那么实际就是要找br-r+bl+l+bm。

   那么就是枚举bm然后找两侧的br-r和bl+l的max。这里只要找到了就一定可以保证是区间三大最大值之一。
