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
#define N 500005
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
vector<ll> v[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      scanf("%d", &n);
      for (int i = 1; i <= n; ++i) {
          scanf("%d", &a[i]);
          v[i].clear();
      }
      sort(a+1, a+n+1);
      map<ll, set<int>> mp;
      mp.clear();
      for (int i = 1; i <= n; ++i) {
          for (int j = i+1; j <= n; ++j) {
              int dt = a[j]-a[i];
              for (ll x = 1; x * x <= dt; ++x) {
                  if ((dt % x) == 0) {
                      ll y = dt/x;
                      if ((x+y)%2) continue;
                      ll p = (x+y)/2;
                      ll q = y-p;
                      ll X = p*p-a[j];
                      if (X >= 0 && X <= 1e18 && q*q >= a[i]) {
                        mp[X].insert(i);
                        mp[X].insert(j);
                      }
                  }
              }
          }
      }
      int ans=1;
      for (auto itr : mp) {
          int sz = (int)itr.second.size();
          if (sz>ans) {
             // cout<<itr.first<<" ";
              ans=max(ans, sz);
              //cout<<ans<<endl;
          }
      }
      printf("%d\n", ans);
  }
  return 0;
}
