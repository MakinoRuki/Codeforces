B. r和b任意前缀的和求最大。

C. 从左到右算出并维护合法范围然后check。

D. 1到n-1都可以除以n得到1，但是n要快速变小。要么开根号要么log，且n要是分好几次逐渐变小的。

   那么可以考虑找一个最大的2^k<=n，然后每次除掉不超过2^(k/2)次幂。
