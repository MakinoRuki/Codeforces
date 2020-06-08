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
#define N 1000005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, p;
int k[N];
ll res[N];
ll getpw(ll a, ll b) {
  ll tmp=1LL;
  while(b) {
    if (b&1) tmp= tmp*a%mod;
    a = a * a %mod;
    b /= 2; 
  }
  return tmp;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &k[i]);
    }
    sort(k+1, k+n+1);
    reverse(k+1, k+n+1);
    if (p==1) {
      if (n&1) cout<<1<<endl;
      else cout<<0<<endl;
    } else {
      vector<pair<int, int>> vs;
      vs.clear();
      for (int i = 1; i <= n; ++i) {
        if (vs.empty()) {
          vs.push_back(make_pair(k[i], 1));
          continue;
        }
        if (k[i] == vs.back().first) {
          vs.back().second--;
        } else {
          vs.push_back(make_pair(k[i], -1));
        }
        while(!vs.empty()) {
          if (vs.back().second == 0) {
            vs.pop_back();
          } else {
            if (vs.back().second == -p) {
              auto pr = vs.back();
              vs.pop_back();
              if (vs.back().first == pr.first+1) {
                vs.back().second--;
              } else {
                vs.push_back(make_pair(pr.first+1, -1));
              }
            } else {
              break;
            }
          }
        }
      }
      ll ans = 0LL;
      for (int i = 0; i < vs.size(); ++i) {
        ll tmp = getpw(p, vs[i].first);
        tmp = tmp * ((vs[i].second + mod) % mod) % mod;
        ans = (ans + tmp) % mod;
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}
