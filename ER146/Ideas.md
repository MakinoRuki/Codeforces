B. 假设最后增加到x，那么操作数就是x+走的步数。如果要走，最佳就是用最大步长x走，如果有余数r就在之前一步走掉。

C. 顺序和>乱序和>反序和。把r从大到小排序之后贪心，看是放到list1还是list2。