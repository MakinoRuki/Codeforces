A. 直接a[i]=i就好了。

***B. 贪心地从左上到右下选2x2小格子变每个位置，但要注意这样会使m列和n行没变化，所以要倒着从右下到左上再来一次。***

C. 枚举abc的顺序然后贪心选择。

D. 通过不断调换a中最后两数的位置，用冒泡的方式把b中前n-2个数放到指定位置。b的总移动次数的奇偶决定a[n-1],a[n]的最终顺序，跟b[n-1],b[n]顺序比较。b的总移动次数用bit统计匹配到a[i]时，idx[a[i]]前有多少没匹配的位置。