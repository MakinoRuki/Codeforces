A. 如果T!=abc或者S中没有同时出现abc那么就所有字母从小到大排序；否则按照acb的顺序。

B. a+b+c=n,gcd(a,b)=c。如果c=1,b=2,那么只要n-3是奇数也就是n是偶数即可；

   否则n是奇数当(n-1)/2是偶数时，c=1,a=(n-1)/2-1,b=(n-1)/2+1相邻奇数必然互素；
   
   否则n是奇数当(n-1)/2是奇数时，c=1,a=(n-1)/2-2,b=(n-1)/2+2相隔一个奇数的两奇数也必然互素。
   
C. 一个数要么保持原样要么由更大的数mod得来，因此如果是[1,n]中的数字那么先保持原样。

   然后如果一个数x想模(y+1)变成y那么必然是y+y+1<=x因此排序之后check需要的数和能变成的数的范围。
   
D1. 如果先query位置1，2和其它所有n-2个位置可以发现如果1，2是01或者10，那么其它所有位置都可以通过结果是0或者1来确定。

   因此就是要找出一个是0一个是1的位置。可以从1到n-2每个位置i都看i,i+1,i+2，然后可以发现如果连续两个i和i+1结果有01的变化那么i+1和i+2必然也是01不同的。