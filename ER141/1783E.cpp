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
#define N 300000
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int b[N];
int cnt[N];
int pmx[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int mx=0;
    pmx[0]=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[i] = 0;
      pmx[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      if (a[i] > b[i]) {
        int dt = a[i]-b[i];
        mx=max(mx, dt);
        cnt[b[i]]++;
        pmx[b[i]] = max(pmx[b[i]], a[i]);
      }
    }
    for (int i = 1; i <= n; ++i) {
      pmx[i] = max(pmx[i], pmx[i-1]);
    }
    vector<int> ans;
    ans.clear();
    for (int k = 1; k <= n; ++k) {
      if (mx >= k) {
        continue;
      }
      int i;
      for (i = k; i <= n; i += k) {
        if (cnt[i] > 0) break;
      }
      if (i <= n) continue;
      for (i = k; i <= n; i += k) {
        if (pmx[i-1] > i) break;
      }
      if (i > n) ans.push_back(k);
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d ", ans[i]);
    }
    cout<<endl;
  }
  return 0;
}
