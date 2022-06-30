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
#define N 200
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
int sa[N], sb[N];
int main() {
//   cin>>t;
// //  mt19937 rnd(time(0));
//   for (int cas=1; cas<=t; ++cas) {
//     scanf("%d", &n);

//   }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      sa[i] = a[i];
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      sb[i]=b[i];
    }
    sort(sa+1, sa+1+n);
    sort(sb+1, sb+1+n);
    bool ok = true;
    vector<pair<int,int>> ans;
    ans.clear();
    for (int i = 1; i <= n; ++i) {
      if (a[i] != sa[i] || b[i] != sb[i]) {
        int j = i+1;
        for (j = i+1; j <= n; ++j) {
          if (a[j] == sa[i] && b[j] == sb[i]) {
            ans.push_back(make_pair(i, j));
            swap(a[i], a[j]);
            swap(b[i], b[j]);
            break;
          }
        }
        if (j > n) {
          ok=false;
          break;
        }
      }
    }
    if (!ok) puts("-1");
    else {
      printf("%d\n", (int)ans.size());
      for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
      }
    }
  }
  return 0;
}
