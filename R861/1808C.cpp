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
    ll l, r;
    scanf("%lld%lld", &l, &r);
    ll ans=0;
    int dt=20;
    for (int d0=0; d0 <= 9; ++d0) {
      for (int d1=max(d0,1); d1<=9; ++d1) {
        vector<int> ds;
        ds.clear();
        ll tmp=l;
        while(tmp) {
          ds.push_back(tmp%10);
          tmp/=10;
        }
        int id0=-1,id1=-1;
        for (int i = 0; i < ds.size(); ++i) {
          if (ds[i] < d0) {
            id0=i;
          }
          if (ds[i] > d1) {
            id1=i;
          }
        }
        if (id0 >= 0 || id1 >= 0) {
          if (id1 < 0 || id0 > id1) {
            for (int i = 0; i <= id0; ++i) {
              ds[i] = d0;
            }
          } else {
            int i = id1+1;
            while(i < ds.size() && ds[i] + 1 > d1) {
              i++;
            }
            if (i >= ds.size()) {
              ds.push_back(1);
            } else {
              ds[i]++;
            }
            i--;
            while(i >= 0) {
              ds[i] = d0;
              i--;
            }
          }
        }
        tmp=0LL;
        int mn=12, mx=-1;
        for (int i = ds.size()-1; i >= 0; --i) {
          mn=min(mn, ds[i]);
          mx=max(mx, ds[i]);
          if (tmp  > r / 10LL) {
            tmp = r+1;
            break;
          }
          tmp = tmp * 10LL;
          if (tmp > r - ds[i]) {
            tmp = r+1;
            break;
          }
          tmp += ds[i];
        }
        if (tmp <= r && mx-mn < dt) {
          dt = mx-mn;
          ans = tmp;
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
