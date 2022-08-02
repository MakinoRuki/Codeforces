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
    vector<int> dt;
    dt.clear();
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a+1, a+m+1);
    for (int i = 1; i <= m; ++i) {
      if (i < m) dt.push_back(a[i+1]-a[i]-1);
      else dt.push_back(n-a[i]+a[1]-1);
    }
    sort(dt.begin(), dt.end());
    reverse(dt.begin(), dt.end());
    ll res = 0LL;
    for (int i = 0; i < dt.size(); ++i) {
      if ((ll)dt[i]-4LL*i>0) res += max((ll)dt[i]-4LL*i-1LL, 1LL);
    }
    printf("%lld\n", n-res);
  }
  return 0;
}
