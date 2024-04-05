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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      int a,b;
      scanf("%d%d", &a, &b);
      v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    map<int,int> mp;
    mp.clear();
    int mx=-1;
    for (int i = 0; i < v.size(); ++i) {
      mp[v[i].second]++;
    }
    int dt=inf+1;
    bool found=false;
    int ans=inf+1;
    for (int i = n-1; i >= 0; --i) {
      mp[v[i].second]--;
      if (mp[v[i].second] == 0) {
        mp.erase(v[i].second);
      }
      dt = inf+1;
      if (mx >= 0) {
        dt = abs(v[i].first-mx);
      }
      if (!mp.empty()) {
        auto itr = mp.upper_bound(v[i].first);
        if (itr != mp.end() && (itr->first >= mx)) {
          dt = min(dt, abs(itr->first-v[i].first));
        }
        if (itr != mp.begin()) {
          itr--;
          if (itr->first >= mx) dt = min(dt, abs(itr->first-v[i].first));
        }
      }
      mx = max(mx, v[i].second);
      ans=min(ans, dt);
    }
    printf("%d\n", ans);
  }
  return 0;
}
