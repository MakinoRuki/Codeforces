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
#define N 100005
#define M 80
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, q;
int k;
int t;
int a[N];
map<int, int> cnt;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll n, x;
    scanf("%lld%lld", &n, &x);
    vector<int> bs;
    bs.clear();
    bool ok = true;
    for (int i = 61; i >= 0; --i) {
      if ((1LL<<i) & n) {
        if ((1LL<<i)&x) continue;
        else bs.push_back(i);
      } else {
        if ((1LL<<i) & x) {
          ok=false;
          break;
        }
      }
    }
    if (!ok) {
      puts("-1");
      continue;
    }
    if (bs.empty()) {
      printf("%lld\n", n);
      continue;
    }
    ll m = n;
    for (int i = 0; i < bs.size(); ++i) {
      int b = bs[i];
      ll r = n % (1LL<<b);
      r = (1LL<<b) - r;
      m = max(m, n+r);
    }
    for (int i = 61; i >= 0; --i) {
      if ((1LL<<i) & n) {
        if ((1LL<<i) & x) {
          ll r = n % (1LL<<i);
          r = (1LL<<i) - r;
          if (m >= n+r) {
            ok=false;
            break;
          }
        }
      }
    }
    if (!ok) {
      puts("-1");
      continue;
    }
    printf("%lld\n", m);
  }
  return 0;
}
