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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int b[N];
ll calc(vector<pair<int,int>>& v) {
  set<pair<int,int>> ss;
  ss.clear();
  ll tot = 0LL;
  for (int i = 0; i < v.size(); ++i) {
    if (ss.find(v[i]) == ss.end()) {
      tot += (ll)abs((ll)a[v[i].first] - (ll)b[v[i].second]);
      ss.insert(v[i]);
    }
  }
  return tot;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> x, y;
    x.clear();
    y.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      // if (i > 1 && i < n) {
      //   x.push_back(make_pair(a[i], i));
      // }
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      // if (i > 1 && i < n) {
      //   y.push_back(make_pair(b[i], i));
      // }
    }
    int id1 = 2, id2 = 2;
    vector<int> a1 = {1, n};
    vector<int> a2 = {1, n};
    // sort(x.begin(), x.end());
    // sort(y.begin(), y.end());
    int id = 2;
    for (int i = 2; i < n; ++i) {
      if (abs(b[1] - a[i]) < abs(b[1] - a[id])) {
        id = i;
      }
    }
    a1.push_back(id);
    id = 2;
    for (int i = 2; i < n; ++i) {
      if (abs(b[n] - a[i]) < abs(b[n] - a[id])) {
        id = i;
      }
    }
    a1.push_back(id);
    id = 2;
    for (int i = 2; i < n; ++i) {
      if (abs(a[n] - b[i]) < abs(a[n] - b[id])) {
        id = i;
      }
    }
    a2.push_back(id);
    id = 2;
    for (int i = 2; i < n; ++i) {
      if (abs(a[1] - b[i]) < abs(a[1] - b[id])) {
        id = i;
      }
    }
    a2.push_back(id);
    ll ans = (1LL<<61) - 1;
    for (int i1 = 0; i1 < 4; ++i1) {
      for (int i2 = 0; i2 < 4; ++i2) {
        for (int j1 = 0; j1 < 4; ++j1) {
          for (int j2 = 0; j2 < 4; ++j2) {
            vector<pair<int,int>> tmp;
            tmp.clear();
            tmp.push_back(make_pair(1, a2[i1]));
            tmp.push_back(make_pair(n, a2[i2]));
            tmp.push_back(make_pair(a1[j1], 1));
            tmp.push_back(make_pair(a1[j2], n));
            ans = min(ans, calc(tmp));
          }
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
