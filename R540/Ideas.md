D. 二分所需天数，然后按照a[i]从大到小依次放到每一天。这样小的放到后面实际上就不会真的减去了。

E. 一共可以组成k*(k-1)对，假设当前放的对是(a,b)那么下一对就是(b,x)其中x是从b+1循环递增到n然后从1递增到b-1。

F. 普通dfs。