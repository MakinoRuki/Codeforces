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
#define N 1000005
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
int p[N];
int lmx[N], lmn[N];
int rmx[N], rmn[N];
vector<int> stk;
vector<ll> sum;
int getr(int lb, int rb, int v) {
  while(lb < rb) {
    int mid = (lb+rb+1)/2;
    if (rmn[stk[mid]] > v) {
      lb = mid;
    } else {
      rb = mid-1;
    }
  }
  if (rmn[stk[rb]] > v) {
    return rb;
  }
  return -1;
}
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
  }
  ll ans = 0LL;
  stk.clear();
  for (int i = 1; i <= n; ++i) {
    lmx[i] = 0, rmx[i] = n+1;
    lmn[i] = 0, rmn[i] = n+1;
  }
  for (int i = 1; i <= n; ++i) {
    while(!stk.empty() && p[stk.back()] > p[i]) {
      rmn[stk.back()] = i;
      stk.pop_back();
    }
    if (!stk.empty()) lmn[i] = stk.back();
    stk.push_back(i);
  }
  stk.clear();
  for (int i = 1; i <= n; ++i) {
    while(!stk.empty() && p[stk.back()] < p[i]) {
      rmx[stk.back()] = i;
      stk.pop_back();
    }
    if (!stk.empty()) lmx[i] = stk.back();
    stk.push_back(i);
  }
  stk.clear();
  sum.clear();
  for (int i = 1; i <= n; ++i) {
    while(!stk.empty() && p[stk.back()] > p[i]) {
      stk.pop_back();
      sum.pop_back();
    }
    if (!stk.empty()) {
      int l = upper_bound(stk.begin(), stk.end(), lmx[i])-stk.begin();
      if (l < stk.size()) {
        ans += (ll)(stk[l]-lmx[i]) * (ll)(min(rmx[i], rmn[stk[l]]) - i);
        l++;
        int r = getr(l, stk.size()-1, rmx[i]);
        //if (i==5) cout<<"x="<<rmx[i]<<" "<<rmn[l]<<" "<<ans<<" "<<l<<" "<<r<<endl;
        ans -= (ll)(stk.back() - stk[l-1]) * (ll)i;
        //if (i==5) cout<<"x="<<ans<<" "<<l<<" "<<r<<endl;
        if (r < 0) {
          ans += sum[stk.size()-1] - sum[l-1];
        } else {
          ans += (ll)(stk[r]-stk[l-1]) * (ll)rmx[i];
          //if (i==5) cout<<"x="<<stk[r]<<" "<<stk[l-1]<<" "<<rmx[i]<<" "<<ans<<" "<<l<<" "<<r<<endl;
          ans += sum[stk.size()-1] - sum[r];
        }
      }
    }
    //cout<<"i="<<i<<" "<<ans<<endl;
    sum.push_back(sum.empty() ? (ll)i * (ll)rmn[i] : sum.back() + (ll)(i-stk.back())*(ll)rmn[i]);
    stk.push_back(i);
  }
  printf("%lld\n", ans);
  return 0;
}
