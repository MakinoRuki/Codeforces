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
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
vector<int> edges[N];
int cnt[N];
void dfs1(int u, int p, ll& tot) {
  cnt[u]=1;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs1(v, u, tot);
    tot += (ll)cnt[v] * (ll)(n-cnt[v]);
    cnt[u] += cnt[v];
  }
}
vector<int> dfs2(int u, int p, ll& tot2, ll& num) {
  vector<int> tmp(k, 0);
  tmp[0]++;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    auto tmp2 = dfs2(v, u, tot2, num);
    for (int j2 = 0; j2 < k; ++j2) {
      for (int j = 0; j < k; ++j) {
        int r = (j2 + j) % k;
        if (r > 0) {
        //  if (u == 1 && tmp[j]*tmp2[j2]>0) cout<<"v="<<v<<" "<<r<<" "<<j<<" "<<tmp[j]<<" "<<j2<<" "<<tmp2[j2]<<endl;
          tot2 += (ll)tmp[j] * (ll)tmp2[j2] * (ll)r;
          num += (ll)tmp[j] * (ll)tmp2[j2];
        }
      }
    }
    for (int j2 = 0; j2 < k; ++j2) {
      tmp[j2] += tmp2[j2];
    }
  }
  int tv = tmp[k-1];
  for (int j = k-1; j >= 1; --j) {
    tmp[j] = tmp[j-1];
  }
  tmp[0] = tv;
  return tmp;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
    
  // }
  cin>>n>>k;
  for (int i = 1; i < n; ++i) {
    int u,v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  memset(cnt, 0, sizeof(cnt));
  ll tot=0LL;
  dfs1(1, 0, tot);
  ll tot2=0LL, num = 0;
  dfs2(1, 0, tot2, num);
 // cout<<tot<<" "<<tot2<<" "<<num<<endl;
  ll ans = (tot - tot2)/k + num;
  printf("%lld\n", ans);
  return 0;
}
