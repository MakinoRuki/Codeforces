A. 小的a跟小的b配，大的a跟大的b配。

B. 贪心。每次从左边去掉最多的左括号，右边去掉最多的右括号，且这俩数要相等。

C. 鸽巢原理。最多m个值不同的pair。如果有相同那就是0。

E. 构造。当你要放i的时候，前面i-1个数最多形成(i-1)/2个ai+aj=ak的pair。依次减去。剩下的位置从后往前从10^9到小放，每次放前一个数减去2n。

   比赛时候减n+1挂掉了！！因为前面放的数字有可能>=n+1！！
