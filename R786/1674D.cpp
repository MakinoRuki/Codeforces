#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <list>
#include <random>
#define N 200005
#define M 502
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    set<pair<int,int>> ss;
    ss.clear();
    bool ok = true;
    for (int i = n; i >= 1; --i) {
      int sz = (int)ss.size();
      if (sz==0) {
        ss.insert(make_pair(a[i], i));
        continue;
      }
      if (sz % 2) {
        auto pr = *ss.begin();
        ss.erase(pr);
        if (ss.size() > 0 && a[i] > (*ss.begin()).first) {
          ok=false;
          break;
        }
        ss.insert(pr);
      } else {
        if (!ss.empty() && a[i] > (*ss.begin()).first) {
          ok=false;
          break;
        }
      }
      ss.insert(make_pair(a[i], i));
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
