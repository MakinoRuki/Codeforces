C. 先按照1-n构造排列，相邻两个位置交换增加2，相隔x的位置交换增加2x，因此1和n交换可以增加2\*(n-1)。然后看2和n-1，以此类推。

***D. 如果某个位置i开始赢不了，那么就要把i之前的全部删掉，否则删掉的比i大的会加到i之前的位置上。而如果删掉i之前的全部还不能使i赢，则只要把i之后的max删掉就好。***