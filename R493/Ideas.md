A. 先把连续的0和1分别合并，分段。真正有意义的两个操作是：把一段0和1倒置；或者把一段0变为1。

   如果x>y那么一段一段地去把0变成1；反之如果x<y那么就通过翻转把所有0的段合并到一起，然后再一起变成1。
   
B. 把1，5，10，50都减掉1，得到0，4，9，49。那么就用0，4，9，49来凑。可以发现如果4或者9的个数>=49，那么其实可以替换成4和或者9个49。以及如果4x+9y>=49也可以替换成49。

   所以4和9的个数不会超过48，它们凑成的和也不会超过48。同理4的个数也不会超过8(否则可以替换成4个9)。因此枚举x个4和y个9，得出(4x+9y)%49=r时x+y的最小值。
   
   剩下的，n-(x+y)个，选49个数不同，凑出的和也就不同，因此就是有n-(x+y)+1种选法。
