B. 一个一个加进去，看跟之前的递增递减关系，并维护不超过加进去的第一个数v[0]。

C. 三维dp，dp[i,j,0/1]表示后i位后面最大数字是多少，是否改动过的max值。

D. 直接贪心合并，但要先考虑结束的右端点小的。也就是先按照右端点排序。

E. 答案就是m-num，其中num是标数的段数。那么就是要num最小，也就是从长到短标。

  因此维护cnt[x]表示长度为x的段数，从大到小把a[i]加进来的过程其实就是找出a[i]的左右边界[l,r]然后减掉a[i]段r-l+1，增加一些a[i]左边的段和右边的段。
