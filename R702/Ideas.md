B. 按照%3分类之后，对于c[0],c[1],c[2]依次暴力check先变成c[i+1]再变成c[i+2]。

G. 首先对于a求一个前缀和，然后对于某个x[i]先算出delta=(x[i]-max{sum[i]})差出几个sum[n]，以及delta%sum的余数是什么。
