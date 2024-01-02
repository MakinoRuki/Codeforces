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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll a[N];
ll sum[M];
int main() {
  ll f0=1,f1=1;
  sum[0]=1;
  sum[1]=2;
  for (int i =2; i <= 55; ++i) {
    ll cur=f0+f1;
    sum[i] = sum[i-1]+cur;
    f0=f1;
    f1=cur;
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &k);
    ll tot=0LL;
    set<pair<ll,int>> ss;
    ss.clear();
    for (int i = 1; i <= k; ++i) {
      scanf("%lld", &a[i]);
      tot += a[i];
      ss.insert(make_pair(a[i], i));
    }
    int i;
    for (i = 0; i <= 55; ++i) {
      if (sum[i] == tot) {
        break;
      }
    }
    if (i > 55) {
      puts("NO");
      continue;
    }
    bool ok=true;
    int pre=-1;
    for (int j = i; j >= 0; --j) {
      ll dt = sum[j];
      if (j > 0) dt -= sum[j-1];
      if (ss.empty()) {
        ok=false;
        break;
      }
      auto pr = *ss.rbegin();
      ss.erase(--ss.end());
      if (pr.second != pre) {
        if (pr.first < dt) {
          ok=false;
          break;
        }
        pr.first -= dt;
        if (pr.first > 0) ss.insert(pr);
        pre=pr.second;
      } else {
        if (ss.empty()) {
          ok=false;
          break;
        }
        auto pr2 = *ss.rbegin();
        ss.erase(--ss.end());
        if (pr.first < dt) {
          ok=false;
          break;
        }
        pr2.first -= dt;
        if (pr2.first > 0) ss.insert(pr2);
        pre=pr2.second;
        ss.insert(pr);
      }
    }
    if (ok && ss.empty()) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
