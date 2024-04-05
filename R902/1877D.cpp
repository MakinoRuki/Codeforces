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
bool vis[N];
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod2;
    x=x*x%mod2;
    y/=2;
  }
  return res;
}
int main() {
  cin>>n;
  memset(vis, false, sizeof(vis));
  vector<pair<int,int>> rk;
  rk.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    rk.push_back(make_pair(a[i], i));
  }
  sort(rk.begin(), rk.end());
  ll ans=0LL;
  int sum=n;
  for (int i = n; i >= 1; --i) {
    int id=rk[i-1].second;
    if (!vis[id]) {
      int tot=0;
      for (int j = 1; j * j <= id; ++j) {
        if ((id%j)==0) {
          if (!vis[j]) tot++;
          if (((id/j) != j) && !vis[id/j]) tot++;
        }
      }
      ll tmp = (getpw(2LL, tot)-1+mod2)%mod2*getpw(2LL, sum-tot)%mod2;
      ans=(ans+(ll)rk[i-1].first*tmp%mod2)%mod2;
      for (int j = 1; j * j <= id; ++j) {
        if ((id%j)==0) {
          vis[j]=true;
          if ((id/j) != j) vis[id/j]=true;
        }
      }
      sum -= tot;
    }
  }
  cout<<ans<<endl;
  return 0;
}
