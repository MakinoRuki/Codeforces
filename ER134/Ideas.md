B. laser必是一个方形会卡住边界，如果可以从上边界或者下边界通过那就可以。

C. 每个位置i是独立的，对于d[i]最小值，只需要找到第一个b[j]>=a[i]即可；对于d[i]最大值，如果选择了j那么从j到i+1的每个a[k]都要不超过b[k-1]。

D. 要使结果尽量大，对于a中以第i位结尾的前缀x应尽量和b中以第i位结尾的前缀y互补。因此一位一位地看，用map维护和check每个前缀在a中和b中个数是否相同。
