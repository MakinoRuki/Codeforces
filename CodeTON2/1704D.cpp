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
#define N 100005
#define M 100005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    vector<pair<ll,int>> c;
    c.clear();
    for (int i = 1; i <= n; ++i) {
      ll x = 0LL;
      for (int j = 1; j <= m; ++j) {
        ll y;
        scanf("%lld", &y);
        x += y*(ll)j;
      }
      c.push_back(make_pair(x,i));
    }
    sort(c.begin(), c.end());
    printf("%d %lld\n", c.back().second, c.back().first-c[c.size()-2].first);
  }
  return 0;
}
