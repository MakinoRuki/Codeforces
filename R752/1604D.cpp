#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
ll k;
int q;
int a[N];
//map<int, int> mp;
int main() {
  // int x,y;
  // // cin>>x>>y;
  // // for (int n = 1; n <= 30; ++n) {
  // //   if (n % x == y % n) {
  // //     cout<<n<<endl;
  // //    // break;
  // //   }
  // // }
  // for (int x = 2; x <= 20; x+=2) {
  //   for (int y = x; y <= 20; y += 2) {

  //     if (y%x != 0) {
  //       cout<<x<<" "<<y<<endl;
  //       for (int n = 1; n <= x+y; ++n) {
  //         if (n%x == y%n) {
  //           cout<<"n="<<n<<endl;
  //         }
  //       }
  //     }
  //   }
  // }
  //cout<<(111488%69420) <<" "<<(42068%111488) <<endl;
  cin>>t;
  int x,y;
  for (int cas=1; cas<=t; ++cas) {
    ll x,y;
    scanf("%lld%lld", &x, &y);
    if (x > y) {
      printf("%lld\n", x+y);
    } else if (x == y) {
      printf("%lld\n", x); 
    } else {
      if (y % x == 0) {
        printf("%lld\n", y);
      } else {
        int det = y/x;
        if (det == 1) {
          printf("%lld\n", (x+y)/2);
        } else {
          printf("%lld\n", ((y/x-1) * x + y)/2);
        }
      }
    }
  }

  return 0;
}
