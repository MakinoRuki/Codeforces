A. 特殊case。单个的a/单个的b。

B. 先考虑最特殊情况就是全部选中，然后看只要有一个数字它的全部power都被包含那它就可以被去掉。

C. 按每一位看，第一次被进位成0是在多大。

D. 筛法+bfs。只把素数入队列进行搜索，处理好每个素数的倍数(a中元素)作为邻接表，然后每个a中元素的素数邻接表。同时记下当前素数由哪个数扩展而来。

   注意大量重复元素的去重。