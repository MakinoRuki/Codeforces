A. 类似i->i+1->i-1->i+2->...->i。这样每个数要么跟两个比自己大的连要么跟两个比自己小的相邻。

B. 先全部用11去凑。凑不成的模11的余数是0->10，如果是r=1->10则拆掉r个99=9*11连成100。

   因此也就是n/11-9*(n%11)>=n%11。也就是n/11>=10*(n%11)。
   
C. 经典贪心。从左到右，能加a[i]就加，小于0了就从前面删掉一个最小的。