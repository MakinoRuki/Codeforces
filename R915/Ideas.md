A. 找规律，先放对角线，然后max(n,m)补完。

B. (叶节点+1)/2。

D. 用栈来维护mex，删掉一个数i时从总和去掉mex(i)，然后看i能踢掉栈顶的多少比它大的mex。
