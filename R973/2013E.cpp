#include <iostream>
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
#define N 500005
#define M 325
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int getgcd(int x, int y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int g = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      g = getgcd(g, a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      a[i] /= g;
    }
    int cur=0;
    ll ans=0LL;
    for (int i = 1; i <= n; ++i) {
      int mn = inf;
      for (int j = 1; j <= n; ++j) {
        mn = min(mn, getgcd(cur, a[j]));
      }
     // cout<<"i="<<i<<" "<<mn<<endl;
      cur = mn;
      ans += cur;
      if (cur == 1) {
        ans += n-i;
        break;
      }
    }
    ans *= g;
    printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

