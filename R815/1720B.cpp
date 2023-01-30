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
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      rk.push_back(make_pair(a[i], i));
    }
    sort(rk.begin(), rk.end());
    int mx1 = rk[n-1].first;
    int mx2 = rk[n-2].first;
    int mn1 = rk[0].first;
    int mn2 = rk[1].first;
    ll ans = mx1+mx2-mn1-mn2;
    printf("%lld\n", ans);
  }
  return 0;
}
