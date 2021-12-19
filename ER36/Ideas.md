D. 拓扑排序变形。每次删掉一条边不需要真的删掉，只要把[u->v]中v的入度-=1即可。

E. 用map去维护不overlap的non-working days的区间，map[l] = r。
