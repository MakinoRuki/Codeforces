B. 直接构造，看r和c的r/2,c/2。

D. 坑题！！因为这样的binary decimal不可能超过2^5个，所以直接dp出所有可以的数字即可。

E. 坑题x2！！因为k必然是n的因子，只有sqrt(n)个，所以直接暴力枚举也没事。

F. 因为2a+b+1==a+b+c，所以a+c=c才有解。然后就是先用b平均地铺满在c叶节点的上面，然后对于a，先补齐b最后一层缺的得到现在component数是x，然后添加log(x)层。

G. 状压dp。dp[i,j]表示保留的song的集合是i，最后一首是j是否existing。
