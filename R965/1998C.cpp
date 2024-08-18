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
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    vector<pair<int,int>> v;
    vector<int> v1;
    v.clear();
    v1.clear();
    for (int i = 1; i <= n; ++i) {
      v.push_back(make_pair(a[i], b[i]));
      if (b[i] == 1) {
        v1.push_back(a[i]);
      }
    }
    sort(v.begin(), v.end());
    vector<int> vr;
    vr.clear();
    for (int i = 0; i < v.size(); ++i) {
      vr.push_back(v[i].first);
    }
    sort(v1.begin(), v1.end());
    vector<ll> sum;
    sum.clear();
    for (int i = 0; i < v1.size(); ++i) {
      if (i == 0) sum.push_back(v1[i]);
      else sum.push_back(sum.back()+v1[i]);
    }
    ll ans=0LL;
    for (int i = 0; i < v.size(); ++i) {
      int id = (n-1)/2;
      if (i < id) {
        if ((n%2)==0)id++;
      } else if (i == id) {
        if (n%2) id--;
        else id++;
      } else {
        if (n%2) id--;
      }
      if (v[i].second == 1) {
        ans = max(ans, (ll)v[i].first+(ll)v[id].first+(ll)k);
      } else {
        ll l = 0, r = 2000000000LL;
        while(l < r) {
          ll mid = (l+r+1)/2;
          int p = upper_bound(vr.begin(), vr.end(), mid)-vr.begin();
          p--;
          if (i <= p) p--;
          if (p+1 < n/2) {
            l = mid;
            continue;
          }
          int p2 = lower_bound(vr.begin(), vr.end(), mid)-vr.begin();
          p2--;
          if (p2+1 >= n/2) {
            ll dt = p2-n/2+2;
            int p3 = lower_bound(v1.begin(), v1.end(), mid)-v1.begin();
            p3--;
            if (p3 + 1 < dt) {
              r = mid-1;
            } else {
              dt = dt * mid - (sum[p3] - (p3-dt>=0?sum[p3-dt]:0));
              if (dt <= k) {
                l = mid;
              } else {
                r = mid-1;
              }
            }
          } else {
            l = mid;
          }
        }
        ans = max(ans, v[i].first+r);
      }
    }
    printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
