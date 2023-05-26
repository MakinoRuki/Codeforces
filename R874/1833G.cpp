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
#define N 200005
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
vector<pair<int,int>> edges[N];
bool ok;
vector<int> ans;
int dfs(int u, int p) {
  int cnt1=0;
  int cnt2=0;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i].first;
    int id = edges[u][i].second;
    if (v == p) continue;
    int res=dfs(v, u);
    if (res<0) {
      ok=false;
      return -1;
    }
    if (res==1) {
      cnt1++;
    } else if (res==2) {
      cnt2++;
    } else {
      ans.push_back(id);
    }
  }
 // cout<<"u="<<u<<" "<<cnt1<<" "<<cnt2<<endl;
  if (cnt1 > 1) {
    ok=false;
    return -1;
  }
  if (cnt1 == 1) {
    if (cnt2 > 0) {
      ok=false;
      return -1;
    }
    return 0;
  }
  if (cnt2 == 0) return 2;
  if (cnt2 == 1) return 1;
  if (cnt2 == 2) return 0;
  ok=false;
  return -1;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ans.clear();
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(make_pair(v, i));
      edges[v].push_back(make_pair(u, i));
    }
    ok=true;
    int res=dfs(1, 0);
    if (!ok || (res!=0)) {
      puts("-1");
    } else {
      printf("%d\n", (int)ans.size());
      for (int i = 0; i < ans.size(); ++i) {
        printf("%d", ans[i]);
        if (i < ans.size()-1) cout<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}
