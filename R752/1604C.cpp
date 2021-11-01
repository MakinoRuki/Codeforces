#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
ll k;
int q;
int a[N];
//map<int, int> mp;
int main() {
  //  int maxv=0;
  // for (int i = 2; i <= 100000; ++i) {
  //   int x=i;
  //   for (int j = 2; j*j <= x; ++j) {
  //     if (x%j == 0) {
  //       int num=0;
  //       while(x%j == 0) {
  //         x/=j;
  //         num++;
  //       }
  //       mp[j] = max(mp[j], num);
  //     }
  //   }
  //   if (x>1) mp[x] = max(mp[x], 1);
  //   maxv = max(maxv, (int)mp.size());
  //   if (mp.size() > 12) {
  //     cout<<i<<endl;
  //     break;
  //   }
  // }
  // cout<<maxv<<endl;
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll g, m;
    map<int, int> cnt;
    cnt.clear();
    bool found=false;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (cnt.size() > 12) continue;
      int x = i+1;
      for (int j = 2; j*j <= x; ++j) {
        if (x%j == 0) {
          int num=0;
          int y=1;
          while(x%j == 0) {
            x/=j;
            y*=j;
            num++;
          }
          cnt[j] = max(cnt[j], y);
        }
      }
      if (x> 1) cnt[x] = max(cnt[x], x);
      bool ok = true;
      for (auto p : cnt) {
        if (a[i] % p.second != 0) {
          ok=false;
          break;
        }
      }
      if (ok) {
        found=true;
      }
    }
    if (found) puts("NO");
    else puts("YES");
  }
  return 0;
}
