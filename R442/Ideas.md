C. 最优答案并不是n+n-2而是n+n/2。先攻击偶数位置上的tanks，然后攻击奇数位置上的，然后再攻击一边偶数位置上的。

   这种一个位置只会影响相邻两个位置的，应该往“奇偶位置交替”考虑。
   
D. 直接bfs爆搜。枚举一个位置上走[1,k]步。但是要注意及时break，也就是剪枝。

E. dfs树转区间+线段树lazy操作维护区间和。