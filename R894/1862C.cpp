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
#define M 100
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
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      cnt[i] = 0;
    }
    set<pair<int,int>> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ss.insert(make_pair(a[i], i));
    }
    for (int i = 1; i <= n; ++i) {
      int sz = (int)ss.size();
      cnt[i] = sz;
      while(!ss.empty() && (*ss.begin()).first<=i) {
        ss.erase(ss.begin());
      }
    }
    if (!ss.empty()) {
      puts("NO");
      continue;
    }
    int i;
    for (i = 1; i <= n; ++i) {
      if (cnt[i] != a[i]) {
        break;
      }
    }
    if (i <= n) puts("NO");
    else puts("YES");
  }
  return 0;
}
