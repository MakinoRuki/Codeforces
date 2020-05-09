C. x和y分开看，最终的x和y也必然是出现过的。

D. 枚举长度为k的substring的起点，枚举RGB/GBR/BRG三种pattern，dp出mod3同余的位置上RGB都出现了几个。

E. d=|w-b|最多为2*min(w,b)+1。先在一行上放wb/bw组合，剩下的贪心地放在这行的上面行/下面行。

F. k<=400，因此多于400条边是没有意义的！！只需要取最短的min(k,m)条边然后bfs就好了！！
