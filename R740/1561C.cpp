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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int t;
int a,b;
vector<int> ks[N];
int main() {
 cin>>t;
 for (int cas=1; cas<=t; ++cas) {
   scanf("%d", &n);
   vector<pair<ll,int>> rk;
   rk.clear();
   for (int i = 1; i <= n; ++i) {
    ks[i].clear();
    int k;
    scanf("%d", &k);
    for (int j = 1; j <= k; ++j) {
      int x;
      scanf("%d", &x);
      ks[i].push_back(x);
    }
    ll minv=ks[i][0]+1;
    for (int j = 1; j < ks[i].size(); ++j) {
      minv=max(minv, (ll)ks[i][j]+1-j);
    }
    rk.push_back(make_pair(minv, (int)ks[i].size()));
   }
   sort(rk.begin(), rk.end());
   ll ans=rk[0].first;
   ll tot=rk[0].first;
   for (int i = 0; i < rk.size(); ++i) {
    if (tot < rk[i].first) {
      ll det=rk[i].first-tot;
      ans+=det;
      tot += det;
    }
    tot += rk[i].second;
   } 
   printf("%lld\n", ans);
 }
 return 0;
}
