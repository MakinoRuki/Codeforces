A. 假设n的最高位1是第x位，那么在1^x之前AND都不是0。只有(1^x)&((1^x)-1)==0。

B. 重点需要记录下是不是回文串。对称位置1，1的pair不考虑，其余只要记下01和00的pair数就可以了。

C. 记下pair(i,j)中的i所在的segment的左端点方案数。

D. 当k=x时，小于x的顶点一定是连成一条链且只能从链的两端扩展出去。假设两端为u和v，u=x，那么mex=x的方案数一定是cnt(subtree(preu)-subtree(u))*cnt(subtree(v))。

   从u=0，v=0开始往minv(subtree(u))=x或者minv(subtree(v))=x扩展。

   
