B. 类似于异或。每个位置上字母计数，多出来的就是没有pair的string。

C. 每个人必然是swap了偶数次，且它会连续swap到一个同奇同偶的位置上。

   因此排序之后每个数字会有一段区间，计数比较这段区间的奇数位置和偶数位置个数。
   
D. 两个1为一组，可以随意移动。因此如果设0和1的个数位n0,n1那么答案就是C(n1/2+n0,n0)。