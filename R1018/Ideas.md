A. 从后往前，依次放max/min。

B. 最坏结果是拿了一堆socks结果一堆都没配上，所以就是先取每一种的max(li,ri)。然后再从大小取k-1个最大的min(li,ri)，再+1，就必然有k种。

***C. 给行+1，不影响相邻两列；给列+1，不影响相邻两行。因此！！行和列是互相不影响的是独立的！！***

***D. 先想到通过操作，按照列去移动每列上相邻的两个bulb，把为1的状态移动；然后发现对x的操作必然是偶数个所以每个x的次数的奇偶不变，但y可能会变，但是！x+y的次数的奇偶也是不变的！！因此看落单的x和x+y即可。***
