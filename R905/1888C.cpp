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
int a[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    cnt[n+1]=0;
    set<int> ss;
    ss.clear();
    for (int i =n; i >= 1; --i) {
      ss.insert(a[i]);
      cnt[i] = (int)ss.size();
    }
    ss.clear();
    ll ans=0LL;
    for (int i = 1; i <= n; ++i) {
      if (ss.find(a[i]) == ss.end()) {
        ans += cnt[i];
      }
      ss.insert(a[i]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
