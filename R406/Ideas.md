C. 只要先求出必胜态和必败态就可以了，从结束必败态开始倒着bfs。

   必败态转移到的一定是必胜态；必胜态更新下一个状态的degree，直到下一个状态全是必胜态那么变成必败态。
   
D. 线段树建图求最短路
