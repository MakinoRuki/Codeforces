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
#include <stack>
#include <bitset>
#define N 2000005
#define M 5002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k;
int t;
int a[N];
int l[N], r[N];
vector<int> v;
ll fac[N];
void dfs(int u) {
  if (l[u]>=0) {
    dfs(l[u]);
  }
  v.push_back(a[u]);
  if (r[u] >= 0) {
    dfs(r[u]);
  }
}
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod2;
    x=x*x%mod2;
    y/=2;
  }
  return res;
}
ll comb(int x, int y) {
//  cout<<"xy="<<x<<" "<<y<<endl;
  ll res=1LL;
  for (int i = x; i >= x-y+1; i--) {
    res=res*(ll)i % mod2;
  }
  res=res*getpw(fac[y], mod2-2) % mod2;
  return res;
}
int main() {
  fac[0]=1LL;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1]  *(ll)i % mod2;
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d%d", &l[i], &r[i], &a[i]);
    }
    v.clear();
    dfs(1);
    ll ans=1LL;
    int cnt=0;
    int pre=-1;
    for (int i = 0; i < v.size(); ++i) {
    //  cout<<"i="<<i<<" "<<v[i]<<endl;
      if (v[i] == -1) cnt++;
      else {
        int len = i-pre-1;
        int dt = v[i]-(pre<0?1:v[pre])+1;
        ans = ans * comb(len+dt-1, len) % mod2;
        pre = i;
      }
    }
    if (v.back()==-1) {
      int len=(int)v.size()-pre-1;
      int dt = m-(pre<0?1:v[pre])+1;
      ans = ans * comb(len+dt-1, len) % mod2;
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

