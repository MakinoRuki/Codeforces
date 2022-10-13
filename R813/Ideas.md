B. 打表找规律，发现如果是奇数从2开始i和i+1互换；偶数就从1开始i和i+1互换。

C. 假设变成0的下标范围是[1,r]那么从左往右看如果第i个位置在r范围内就必须变0；否则如果i往后还有逆序对则i也必须变0。

   而i往后是否有逆序对可以dp预处理。
   
D. 二分答案m，那么其实就是要求存在任意一个[l,r]区间，区间上最小值设为x，区间外任意一个下标i的min[l,i]+min[r,i]设为y，满足min{x,y}>=m。

   那么区间上小于m的必须要改，区间外y<=ceil(m/2)-1的必须要改。用S1表示第一种的个数前缀和，S2表示第二种个数前缀和，X设为第二种total。
   
   那么也就是找一个最小的z=S1[r]-S1[l-1]+X-(S2[r]-S2[l-1])，满足z<=k。