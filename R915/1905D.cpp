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
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll a[2*N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    for (int i = n+1; i <= 2*n; ++i) {
      a[i] = a[i-n];
    }
    ll cur=0LL;
    ll ans=0LL;
    list<int> ids;
    ids.clear();
    ll sum=0LL;
    for (int i = 1; i <= n; ++i) {
      while(!ids.empty() && a[i] < a[ids.back()]) {
        auto id = ids.back();
        ids.pop_back();
        if (!ids.empty()) {
          cur -= a[id] * (ll)(id-ids.back());
        } else {
          cur -= a[id] * (ll)(id-1);
        }
      }
      if (ids.empty()) {
        cur += a[i] * (ll)(i-1);
      } else {
        cur += a[i] * (ll)(i-ids.back());
      }
      ids.push_back(i);
    }
    ans = cur;
    for (int i = n+1; i < 2*n; ++i) {
      while(!ids.empty() && a[i] < a[ids.back()]) {
        auto id = ids.back();
        ids.pop_back();
        if (!ids.empty()) {
          cur -= a[id] * (ll)(id-ids.back());
        } else {
          cur -= a[id]* (ll)(id-(i-n));
        }
      }
      if (!ids.empty() && ids.front() == i-n) {
        ids.pop_front();
      }
      if (!ids.empty()) {
        cur -= a[ids.front()];
        cur += a[i] * (ll)(i-ids.back());
      } else {
        cur += a[i] *(ll)(n-1);
      }
      ids.push_back(i);
      ans=max(ans, cur);
    }
    printf("%lld\n", ans+n);
  }
  return 0;
}
