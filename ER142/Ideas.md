A. 只有1会两个一起消失。

B. 分情况讨论，先做a[1]然后a[2]/a[3]中多的先做。

C. 因为一直是往两边放，所以必然是中间一段数字不动。

   n为奇数则以(n+1)/2为中心看向两边能扩展多少不动的，n为偶数则以n/2,n/2+1为中心看能扩展多少不动的。
   
D. 对于p*\q，可以考虑每个排列作为q排列，如果设排列中i的位置是idx[i]，那么从1到n用trie树维护idx[1]->idx[n]的prefix的排列有多少个。然后查询。