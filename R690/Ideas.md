D. 最后必然是分成一些连续的段。枚举第一段的和再O(n)去check。

E. 排序之后枚举最小值l，找到最大值可选边界r，在[l+1, r]之间选择m-1个。

F. 先把区间按照右端点排序，枚举最后set中跟所有其它区间相交的线段，BIT维护左右相交的条数。
