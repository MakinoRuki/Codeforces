E. 经典子集dp。最终结果必然是一些环。先找环，同时状态压缩s记录已经遍历到的i，更新dp[s]。然后dp算出s的超集。这个dp有个O(3^n)的算法。
