A. 用+i/-i和2xc/-xc，2yc/-yc来凑。

B. 把p往左shift一个位置就得到q。

C. 把a排序之后，对于每个a[i]，如果b[i]=1那么直接把k加到a[i]上最优；否则把b[i]=1的a[i]也排序得到v，二分median，小于等于median的a[i]要超过一半，同时如果小于median的a[i]的个数x超过一半m就要从v中挑最大的dt=x-m个用k来调整。
