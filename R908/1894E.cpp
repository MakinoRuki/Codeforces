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
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
map<ll, ll> ln, rn, an;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &m);
    ln.clear();
    rn.clear();
    an.clear();
    ll totl =0LL, totr=0LL;
    set<ll> ss;
    ss.clear();
    for (int i = 1; i <= m; ++i) {
      ll l, r;
      scanf("%d%lld%lld", &n, &l, &r);
      totl += l;
      totr += r;
      vector<ll> va, vc;
      va.clear();
      vc.clear();
      ll tot=0LL;
      for (int j = 1; j <= n; ++j) {
        ll x;
        scanf("%lld", &x);
        va.push_back(x);
        ss.insert(x);
      }
      for (int j = 1; j <= n; ++j) {
        ll x;
        scanf("%lld", &x);
        vc.push_back(x);
        tot += x;
      }
      for (int j = 0; j < n; ++j) {
        rn[va[j]] += r;
        ll dt = tot - vc[j];
        if (dt < l) {
          an[va[j]] += l-dt;
          ln[va[j]] += l;
        } else {
          ln[va[j]] += dt;
        }
      }
    }
    vector<ll> v(ss.begin(), ss.end());
    if (v.back() < totl) {
      puts("0");
      continue;
    } else if (v[0] > totr) {
      puts("0");
      continue;
    } else {
      int lb=0, rb =v.size()-1;
      while(lb < v.size() && v[lb] < totl) {
        lb++;
      }
      while(rb >= 0 && v[rb] > totr) {
        rb--;
      }
      if (lb <= rb && rb-lb+1<totr-totl+1) {
        puts("0");
        continue;
      }
    }
    ll ans = -1;
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] >= totl && v[i] <= totr) {
        ll dt = totr - rn[v[i]];
        ll dt2 = max(v[i] - (dt+ln[v[i]]), 0LL);
        ans = (ans < 0 ? dt2 + an[v[i]] : min(ans, dt2 + an[v[i]]));
      }
    }
    printf("%lld\n", (ans<0?0:ans));
  }
  return 0;
}
