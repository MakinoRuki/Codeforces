A. a=1, b=x-1。

B. 数组里distinct的数字个数。

C. 尽量先把大的数字放在经过pair多的边上。

D. d=(v-u)/2是各位上的进位情况，先看两个数字能不能满足，能满足就2个；不能满足就3个。注意1个的情况。

   强调！！三个0/1相加，不可能有超过1位的进位！！！
   
E. 每个数先把能除掉的完全平方数除掉之后，剩下的必然是1 or p or p*q(p,q素数)的情况。那么两个素数之间连一条边，所形成图中找一个最短环。

   注意找p和q的时候，使用dp的方法。对每一个数记录它的最大素因子fp[i]，那么res[i]该由res[i/fp[i]]得来。
   
F. 感觉比较经典。找最大独立集的一个经典贪心算法，每次找degree最少的点加进set，然后remove所有邻接点邻接边。

   这样以来，假如可以找到sqrt(n)个点，则1任务达成；否则剩下的图所有degree>=sqrt(n)-1，那么这样的图中必然存在长度>=sqrt(n)的环。
   
   一直找到，某个点在环上出现位置最小。
