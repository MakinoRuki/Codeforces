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
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    vector<int> v1, v2;
    v1.clear();
    v2.clear();
    set<int> ss;
    ss.clear();
    ll ans = 1LL;
    for (int i = 1; i <= n; ++i) {
      if (b[i] >= 1) {
        ss.insert(b[i]);
        if (a[i] <= b[i] || a[i] <= b[i]+m) {
          continue;
        }
        ans = 0LL;
        break;
      } else {
        v1.push_back(a[i]);
      }
    }
    if (ans <= 0LL) {
      printf("%lld\n", ans);
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      if (ss.find(i) == ss.end()) {
        v2.push_back(i);
      }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int i = 0;
    for (int j = 0; j < v2.size(); ++j) {
      while(i < v1.size() && v1[i] <= v2[j]+m) {
        i++;
      }
      int dt = i - j;
      if (dt <= 0) {
        ans = 0LL;
        break;
      }
      ans = ans * (ll)dt % mod2;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
