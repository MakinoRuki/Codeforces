A. 所有"#"处的行和列要用并查集合并，之后看所有在同一集合的行和列交叉处有没有"#"。

B. a[i]<a[j]<a[k],(a[k]-a[j])/(a[k]-a[i])最大必然是j=i+1,k尽可能大。sliding window。

C. 从前往后直接贪心。到i为止的记号必然连续，只需要记下一共几个。不需要增加就不增加，需要增加时，对于j>i且那么必然满足sum[i]>=m[j]-(j-i-1)。
