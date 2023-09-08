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
#define N 200010
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
ll sum[N];
ll p[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<int> ids;
    ids.clear();
    ll tot = 0LL;
    ll ans = 0LL;
    sum[0] = 0LL;
    bool found=false;
    p[0] = 1LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      sum[i] = sum[i-1] + a[i];
      if (a[i] > 1) {
        ids.push_back(i);
      }
      tot += a[i];
      ans += a[i];
      if (p[i-1] >= (1LL<<60)/(ll)a[i]) {
        found=true;
      } else {
        p[i] = p[i-1] * (ll)a[i];
      }
    }
    int sz = (int)ids.size();
    if (sz >= 60 || found) {
      int l = 1, r = n;
      while(l < r && a[l] == 1) l++;
      while(r > l && a[r] == 1) r--;
      printf("%d %d\n", l, r);
      continue;
    }
    int l1 = 1, r1=1;
    for (int i = 0; i < ids.size(); ++i) {
      for (int j = i; j < ids.size(); ++j) {
        int l = ids[i];
        int r = ids[j];
        ll cur = tot - sum[r] + sum[l-1];
        cur += p[r] / p[l-1];
        if (cur >= ans) {
          l1 = l, r1 = r;
          ans = cur;
        }
      }
    }
    printf("%d %d\n", l1, r1);
  }
  return 0;
}
