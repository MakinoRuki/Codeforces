A. 先做xy较小的那边，降到达不到之后再看能不能做另一边。

B. 看两块已经存在的，如果它们有一条边刚好卡住，必然是yes；否则就看有一定距离的每一维，是否可以塞上完整的axb。

***C. 第一块不管放在哪，中间部分都要浪费掉。但我们能做到的是，在之后的每一次都不浪费(只要每次只多扩展一行或一列就好)。***

D. 可以发现删掉的一定是两边top的一些卡片。如果我们可以枚举player要得几分x，就可以知道dealer需要得n-x分。那么dealer的第n-x+1张卡必然是这n+1张中最小的，才能保证player先得完x分。因此可以两指针枚举，player从少到多枚举x，dealer从多到少维护set，如果第n-x+1不是最小的，就把player的前x张卡的最小值跟TA自己后n-x张最大值交换，再看dealer的n-x+1张是不是最小。
