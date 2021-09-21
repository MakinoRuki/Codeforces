B. 算出相邻想等pair的个数范围看m在不在其中。

C. 把a排序然后对于x二分出在a中的upperbound是id，然后要么排出id打怪要么排出id-1。

D. 类似于trie树去组织那些ban掉的序列，然后在trie树上dfs，如果某个level选了没被ban的前缀那么后面每层都选最大值。

