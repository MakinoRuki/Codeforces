A. 直接枚举12和23和13多少平局。

B. 按位拆开之后对每位来说，k是单调的，可以二分。

C. 猜测答案必然是(n-1)/2。因此把中间的位置抽出来尽量安排大数，剩余位置抽出来安排剩下的小数；起始位置枚举2和3，找到和较大的。
