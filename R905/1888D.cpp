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
int b[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    sort(a+1, a+n);
    sort(b+1, b+n+1);
    vector<int> v;
    v.clear();
    int r = 1;
    ll ans=0;
    ll cur=0LL;
    for (int i = 1; i < n; ++i) {
      while(r <= n && b[r] <= a[i]) {
        v.push_back(b[r]);
        r++;
      }
      if (r <= n) {
        cur++;
        r++;
      } else {
        break;
      }
    }
    while(r <= n) {
      v.push_back(b[r++]);
    }
    ll dt = min((ll)m, (ll)v.back()-1);
    ans += dt * (n-(cur+1));
    if (m > dt) {
      dt = m-dt;
      ans += dt * (n-cur);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
