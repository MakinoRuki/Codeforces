
#include <iostream>
#include <sstream>
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
#include <chrono>
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int b[N];
vector<int> edges[N];
vector<int> ans;
void dfs(int u) {
  int vv=0;
  for (auto v : edges[u]) {
    if (edges[v].empty()) {
      ans.push_back(v);
    } else {
      vv=v;
    }
  }
  if (!vv) return;
  ans.push_back(vv);
  dfs(vv);
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // ll ans=1LL;
  // for (int i =1; i <= 500; ++i) {
  //   ans=ans*5813LL%9422LL;
  // }
  // cout<<ans<<endl;
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    edges[0].clear();
    edges[n+1].clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      edges[i].clear();
    }
    int mn=inf,mx=0;
    int rt=0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] > n) {
        rt = n+1;
        mx=max(mx, i);
      } else if (a[i] < 1) {
        mn=min(mn, i-1);
      } else {
        int l=min(i,a[i]);
        int r=max(i,a[i]);
        mx=max(mx,l);
        mn=min(mn,r-1);
      }
      edges[a[i]].push_back(i);
    }
    ans.clear();
    dfs(rt);
    printf("%d\n", mx);
    for (auto x : ans) {
      printf("%d ", x);
    }
    cout<<endl;
  }
  return 0;
}
