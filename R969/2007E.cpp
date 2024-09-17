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
int p[N];
vector<int> edges[N];
int par[N];
ll mx[N];
int find(int x) {
  return x == par[x] ? x : par[x] = find(par[x]);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll w;
    scanf("%d%lld", &n, &w);
    par[1] = 1;
    mx[1] = 1;
    for (int i = 2; i <= n; ++i) {
      scanf("%d", &p[i]);
      par[i] = i;
      mx[i] = i;
    }
    ll cur = 0LL;
    ll cnt = n;
    vector<ll> ans;
    for (int i = 1; i < n; ++i) {
      int x;
      ll y;
      scanf("%d%lld", &x, &y);
      int l = x-1, r1=mx[x]%n+1;
    //  int r2 = mx[p[x]]+1;
      int pl = find(l);
      int pr1 = find(r1);
      int pp = find(p[x]);
      //int pr2 = find(r2);
    //  cout<<"i="<<i<<" "<<l<<" "<<r1<<" "<<pl<<" "<<pr1<<endl;
      if (pl == pp) cnt--;
      if (pr1 == pp) cnt--;
     // if (pr2 == x) cnt--;
      mx[pp] = max(mx[pp], mx[par[x]]);
      par[x] = pp;
    //  cout<<"pp="<<pp<<" "<<mx[pp]<<endl;
      cur += y;
    //  cout<<"cur="<<cur<<" "<<"cnt="<<cnt<<endl;
      ll tmp = cur * 2LL + cnt * (w-cur);
      ans.push_back(tmp);
    }
    for (int i = 0; i < ans.size(); ++i) {
      printf("%lld ", ans[i]);
    }
    cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

