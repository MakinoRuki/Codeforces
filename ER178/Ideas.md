C. 取决于1，n，n-1在谁手里。直接讨论。

D. beautiful变ideal肯定是把所有超过2的部分全收上来，然后去凑成尽量多的小素数。注意可以不用全用完！！然后肯定是选最大的x个保留，去凑最小的x个素数。

E. 对于一个t来说，肯定是先尽量跟s的前边部分匹配。配完之后，假设结束位置是id，那么id之后s中如果所有字母都出现一遍那么肯定不能只append一个，以此类推，要看id之后所有字母都出现一遍的block块数，可以dp。
