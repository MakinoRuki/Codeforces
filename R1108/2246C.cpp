
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
#define N 2000005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
const int base=337;

int n, m, q;
ll k, w;
int t;
ll a[N];
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod;
    x=x*x%mod;
    y/=2;
  }
  return res;
}
int main() {
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      if (rk.empty()) {
        rk.push_back(make_pair(a[i], 1));
      } else {
        if (a[i] == rk.back().first) rk.back().second++;
        else rk.push_back(make_pair(a[i], 1));
      }
    }
    int sz=(int)rk.size();
    ll ans = getpw(2LL, n-sz);
    if (rk[0].first == -1) {
      for (int i = 2; i < rk.size(); ++i) {
        if (rk[i].first == rk[i-1].first+1) {
          ans = (ans + getpw(2LL, n-sz)) % mod;
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
