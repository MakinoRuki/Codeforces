C. 把奇数位置和偶数位置分开，分别求gcd。假设g1<g2那么用d=g2,然后看是否另一部分还是能被整除。

D. 用最后2K个数相除。

E. 写写看看发现可以相邻的b[i]相减求出a[i]。

F. 必须x是y的中间一段两端加上1。不过还WA着...

G. 所有的a[i]和b[i]一起排序，从小到大把它们并在一起用最大值作为根向右合并。那么这个集合[l,r]里有x个a[i]就要求sum[r]-sum[r-x]。