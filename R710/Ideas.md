D. 经典套路，出现次数最多的v的出现次数大于其余的和s则两两配对后剩下s-v，否则剩下0。

E. 贪心。最大值只会单调不递减。因此每次放最小或者最大。

F. 坐标排序之后找规律，对于(r,c)如果r+c是偶数必然走一步变奇数之后一直偶数下去；否则一直奇数。

G. 用stack维护字母序列，但是要注意当前字母在顶掉栈顶字母时候，如果当前字母之前出现过了就不要顶了。
