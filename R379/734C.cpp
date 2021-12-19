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
#define N 200005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N], b[N], c[N], d[N];
int main() {
  cin>>n>>m>>k;
  int x,ub;
  cin>>x>>ub;
  ll tot = (ll)n * (ll)x;
  vector<pair<int,int>> rk;
  rk.clear();
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &b[i]);
  }
  for (int i = 1; i <= k; ++i) {
    scanf("%d", &c[i]);
  }
  for (int i = 1; i <= k; ++i) {
    scanf("%d", &d[i]);
  }
  for (int i = 1; i <= k; ++i) {
    rk.push_back(make_pair(d[i], i));
  }
  sort(rk.begin(), rk.end());
  vector<int> v1;
  vector<ll> v2;
  v1.clear();
  v2.clear();
  v2.push_back(0);
  for (int i = 0; i < rk.size(); ++i) {
    v1.push_back(rk[i].first);
    v2.push_back(c[rk[i].second]);
  }
  for (int i = 1; i <= k; ++i) {
    v2[i] = max(v2[i-1], v2[i]);
  }
  for (int i = 1; i <= m; ++i) {
    if (b[i] <= ub) {
      tot = min(tot, (ll)a[i] * (ll)n);
    }
  }
  for (int i = 1; i <= k; ++i) {
    if (d[i] <= ub) {
      tot = min(tot, (ll)max(n-c[i], 0) * (ll)x);
    }
  }
  for (int i = 1; i <= m; ++i) {
    ll det = ub - b[i];
    if (det > 0) {
      auto id = upper_bound(v1.begin(), v1.end(), det) - v1.begin();
      id--;
   //   if (i == 2) cout<<"id="<<id<<endl;
      if (id >= 0 && id < k) {
        ll det = max(0LL, n-v2[id+1]);
        tot = min(tot, det * (ll)a[i]);
      }
    }
  }
  cout<<tot<<endl;
  return 0;
}
