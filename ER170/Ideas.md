A. 两个string只有前缀可以share，于是找最大前缀。

B. 找找规律，跟n没有关系，只跟k有关系，是2^k。

C. 把连续差1的一些段找出来，找k个不同的最多个数。

D. 直接dp，每个point去group它之后的check，dp[i,j]表示前i个point给了一种j个的最大pass数，然后在当前point的checks里面二分。

***E. 对于第一行，任意一个时刻可以是第一个人赢得多，也可以是第二个人赢得多，但是第一行结束之后，第一个人赢的可以多余用来抵消后面行第二个人赢的，但第二个人需要已经完全抵消掉；对于其他行，任意一个时候都必须是第二个人赢得多或者两者相同，这样第二个人多余的才能用第一行多的来抵消。所以先dp出每一行第二个人多余j2的方案数，再dp前i行弄完第一行剩余j的方案数，两者相乘去转移。*** 
