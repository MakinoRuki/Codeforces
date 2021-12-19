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
#define N 200
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q, p;
int l, r;
int t;
string s;
ll x;
ll tot[N];
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll ans=0LL;
    ll tot=0LL;
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      tot=max(tot, (ll)a[i]);
      ss.insert(a[i]);
    }
    ans = tot;
    for (int n1 = 0; n1 <= 2; ++n1) {
      for (int n2 = 0; n2 <= 2; ++n2) {
        int n3 = 0;
        int i;
        for (i = 1; i <= n; ++i) {
          int c3 = -1;
          for (int c1 = 0; c1 <= n1; ++c1) {
            for (int c2 = 0; c2 <= n2; ++c2) {
              int det = a[i] - c1 - c2 * 2;
              if (det == 0 || det % 3 == 0) {
                c3 = (c3 < 0 ? det / 3 : min(c3, det/3));
              }
            }
          }
          if (c3 < 0) break;
          n3 = max(n3, c3);
        }
        // if (n1 == 2 && n2 == 0) {
        //   cout<<"i="<<i<<endl;
        // }
        if (i > n) {
          ans = min(ans, (ll)(n1 + n2 + n3));
        }
      }
    }
    // n = (int)ss.size();
    // int i = 0;
    // for (auto itr : ss) {
    //   a[++i] = itr;
    // }
    // ans = tot;
    // ll mv = 0LL;
    // for (int i = 1; i <= n; ++i) {
    //   a[i] %= 3;
    //   mv = max(mv, (ll)a[i]);
    // }
    // ll n3 = (tot - mv) / 3;
    // tot -= n3 * 3;
    // ans = ans - n3 * 3 + n3;
    // mv = 0;
    // for (int i = 1; i <= n; ++i) {
    //   a[i] %= 2;
    //   mv = max(mv, (ll)a[i]);
    // }
    // ll n2 = (tot - mv) /2;
    // ans = ans - n2 * 2 + n2;
     printf("%lld\n", ans);
  }
  return 0;
}
