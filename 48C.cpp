/* 根据前n个停车站，可以算出alpha的上下界，是[10\*a[j]/j, 10\*(a[i]+1)/i]。先在需要找的是(n+1)\*alpha<10\*(x+1)中的x，也就是(n+1)\*alpha/10<(x+1)。
(n+1)\*alpha/10的范围是[(n+1)a[j]/j, (n+1)(a[i]+1)/i)。现在需要x满足的是，alpha可以取到x，但是不一定能取到x+1。可以直接看x+1的取值方法。
如果下边界L=(n+1)a[j]/j是一个整数，那么x+1一定不能选它，但如果L不是整数，x+1就可以取ceil(L)。另外，x+1是可以取R=(n+1)(a[i]+1)/i的，只要x在alpha取值范围内。
因此就在[L,R]中找满足条件的x+1的个数。从而找出一个可以的x。*/

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 3000005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod1 = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
//int ans[N];
int dp[N][2][2];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
    
  // }
  // string s2;
  // cin>>s2;
  // cout<<"sz="<<(int)s2.size()<<endl;
  cin>>n;
  ll x1 = 1, y1 = 1;
  ll x2 = 1, y2 = 1;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (i == 1) {
      x1 = 10*a[i];
      x2 = 10*a[i]+10;
    } else {
      ll xx = 10*a[i], yy = i;
      // 也要考虑下边界！！
      if (xx * y1 > yy * x1) {
        x1 = xx;
        y1 = yy;
      }
      xx = 10*a[i]+10, yy = i;
      if (xx * y2 < x2 * yy) {
        x2 = xx, y2 = yy;
      }
    }
  }
 // cout<<"xy="<<x<<" "<<y<<endl;
  //x = (n+1)*x-10*y;
  //cout<<"xy="<<x<<" "<<y<<endl;

//   ll v1 = 10*(n+1);
//   ll v2 = (a[n]+2)*10;
//   ll v = max(v1, v2);
//   int cnt=0;
//   ll cur = v;
//   while(true) {
//     cnt++;
//     if (cur * y >= (n+1)*x) {
//       break;
//     }
//     if (cnt > 1) break;
//     cur += 10;
//   }
//  // cout<<"v="<<v<<" "<<"vv="<<vv<<endl;
//   if (cnt > 1) {
//     puts("not unique");
//   } else {
//     puts("unique");
//     printf("%lld\n", v/10-1);
//   }

  x1 *= (n+1);
  x2 *= (n+1);
//  cout<<"xy="<<x1<<" "<<y1<<endl;
  ll v = (x1/(10*y1)+1) * 10;
  int cnt=0;
  ll cur = v;
  while(true) {
    cnt++;
    if (cur * y2 >= x2) {
      break;
    }
    if (cnt > 1) break;
    cur += 10;
  }
  if (cnt > 1) {
    puts("not unique");
  } else {
    puts("unique");
    printf("%lld\n", v/10-1);
  } 
  return 0;
}
 
