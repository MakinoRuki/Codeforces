A. 全部2的power。

B. 把local max找出来，然后相隔为1的可以两个一起合并。

C. 最后两个一定不能变，从后往前看第i个只要a[i]>a[i+1]那么就a[i]=a[i+1]-a[n]。

D. 只要A不是B的一系列操作得到的，那么A和B得出的数字就不可能重复，因此只看位数。去重时候看A结尾的1删掉，以及偶数个0删掉。
   
E. 方向相同的永远不可能满足条件，只要有关系就必须是方向不同的。因此二分图染色，然后0是L，1是R。
    
   然后根据关系确定大小关系，建图，拓扑排序。
   
