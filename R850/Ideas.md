B. 从第一块蛋糕开始尽量左边缘对齐，之后维护最多可以往左shift的量。

C. 看用type2操作最多可以省多少操作。type2的使用范围一定是[1,n]最优，因为可以省更多。排序之后每个按照可以省1->n贪心。

D. 预处理出一些(x,y)的pair表示可以给出x并需要y。先是(x,y)/(y,x)两两配对，剩下的必然是(x,y)->(y,z)->(z,x)这样3组的2步交换。