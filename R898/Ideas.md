H. 先找出环上的点，如果V不在环上那么必须比M先上环。从V开始dfs到的第一个重复出现的点就是环开始的位置，从这个位置bfs最短路。