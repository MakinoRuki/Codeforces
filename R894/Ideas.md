C. 根据a[1]-a[n]可以找出大于等于1的，2的...大于等于n的至少有几个。

D. 找出最大的m满足m\*(m-1)/2<=n，然后差x就弄x个duplicate的数字。

E. 每过一天就会cost一个d，这个cost不可避免。之后从左到右扫一遍theater找出最大的m个收益就好。

F. dp[i,j]表示前i个monster话费w为j时消灭这些monster最少多少天。话费的f可以算出来。

G. 排序之后给各个a[i]加上的数字并不能改变a[i]之后的顺序，而是每次将两数之间的delta减少1，达到相等的时候就会合并两个a[i]。

  设b数组是a数组的两两之间delta，如果假设b1有c1个，...bx有cx个，那么就是给a[1]加上b1个n，再加上b2个n-c1，以此类推。

  最终答案就是a(min)+delta的sum+delta的max。
