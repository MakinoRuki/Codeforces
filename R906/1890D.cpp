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
ll a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    vector<pair<ll, int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      if (i!=1) rk.push_back(make_pair(a[i], i));
    }
    sort(rk.begin(), rk.end(), [](const pair<ll,int>& x, const pair<ll,int>& y) {
      return x.first-(ll)x.second*(ll)m > y.first - (ll)y.second*(ll)m;
    });
    ll sum=a[1];
    bool ok=true;
    for (int i = 0; i < rk.size(); ++i) {
      if (sum + rk[i].first < (ll)rk[i].second * (ll)m) {
        ok=false;
        break;
      }
      sum += rk[i].first;
    }
    if (ok) puts("Yes");
    else puts("No");
  }
  return 0;
}
