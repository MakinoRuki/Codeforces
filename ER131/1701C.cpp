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
#define eps 1e-8
#define N 200005
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
    scanf("%d%d", &n, &m);
    map<int,int> mp;
    mp.clear();
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &a[i]);
      mp[a[i]]++;
    }
    int sz = (int)mp.size();
    ll l = 0, r = 1000000000;
    while(l < r) {
      ll mid = (l+r)/2;
   //   cout<<"v="<<l<<" "<<r<<" "<<mid<<endl;
      int cnt = 0;
      for (int i = 1; i <= n; ++i) {
        if (mp.find(i) != mp.end()) {
          int dt = max(mp[i]-mid, 0LL);
          cnt += dt;
        }
      }
      for (int i = 1; i <= n; ++i) {
        if (mp.find(i) == mp.end()) {
          cnt = max(cnt - mid/2, 0LL);
        } else {
          ll dt = mid - mp[i];
          if (dt > 0) {
            cnt = max(cnt - dt/2, 0LL);
          }
        }
      }
    //  if (mid == 2) cout<<"cnt="<<cnt<<" "<<sz<<endl;
      if (cnt <= 0) {
        r = mid;
      } else {
        l = mid+1;
      }
    }
    printf("%lld\n", r);
  }
  return 0;
}
