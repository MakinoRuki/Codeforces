A. A+(B-1)*A=B*A。

B. 选最小的数字x，把整个数组变成x，x+1交替。

C. 分析一下这两个操作。1号操作是利用(a,b)求出a和b中较大数字。因此只要求出全局最小的下标(也就是1)就能知道其他数字。

   而如何通过操作2得到1的位置。可以讨论一下就发现每次可以相邻两个位置(奇偶)一起query，然后两个一起确定是不是。这样就是n/2次。
