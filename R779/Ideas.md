A. 两个0之间至少2个1。

B. 打表找规律，偶数必须放奇数位置，奇数必须放偶数位置。

C. 先找到为1的位置就是最大值所在。然后从1之后一个一个check，和前一个可以增大不超过1可以相等可以减小但不能小于2。

D. (D1)可以看每一位根据0/1个数哪个多哪个少确定x这一位是1/0。

   但general的情况是枚举x是某个a[i]^l，然后check时候用binary-trie看最大最小值在[l,r]之间。
