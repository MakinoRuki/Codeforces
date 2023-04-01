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
#define N 200005
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    ll ans = 0LL;
    set<pair<int,int>> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      if (a[i] > 0) {
        ss.insert(make_pair(-a[i], i));
      } else if (!ss.empty()) {
        auto itr = *ss.begin();
        ss.erase(itr);
        ans -= itr.first;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
