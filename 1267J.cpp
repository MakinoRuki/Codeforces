/* dfdsfd */

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
#include <chrono>
#define N 3000005
#define M 50
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x,y;
    scanf("%d", &n);
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
      b[i]=0;
    }
    for (int i = 1; i <= n; ++i) {
      b[a[i]]++;
    }
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i =1; i <= n; ++i) {
      if (b[i]) {
        rk.push_back(make_pair(b[i], i));
      }
    }
    sort(rk.begin(), rk.end());
    ll ans=-1;
    for (int s = 1; s <= rk[0].first+1; ++s) {
      ll tot=0LL;
      for (int j = 0; j < rk.size(); ++j) {
        int x = rk[j].first;
        if (s == 1) tot += x;
        else {
          if ((x%s)==0) {
            tot += x/s;
            continue;
          }
          int q = x/s;
          // 最多剩下一盒的量，只要能补成1盒s-1就行。
          if ((ll)(q+1)*(ll)(s-1)<=x) {
            tot += q+1;
          } else {
            tot = -1;
            break;
          }
        }
      }
      if (tot >= 0) ans = (ans < 0 ? tot : min(ans, tot));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
