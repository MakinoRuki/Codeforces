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
int par[N];
vector<string> v[N];
int find(int u) {
  return u == par[u] ? u : par[u] = find(par[u]);
}
void merge(int u, int v) {
  int pu = find(u);
  int pv = find(v);
  if (pu != pv) {
    par[pu] = pv;
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    string s1, s2;
    cin>>s1>>s2;
    for (int i = 1; i <= n; ++i) {
      par[i] = i;
      v[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
      if (i + k <= n) {
        merge(i, i+k);
      }
      if (i+k+1<=n) {
        merge(i, i+k+1);
      }
    }
    for (int i = 1; i <= n; ++i) {
      v[i].push_back("");
      v[i].push_back("");
    }
    for (int i = 1; i <= n; ++i) {
      par[i] = find(i);
      v[par[i]][0].push_back(s1[i-1]);
      v[par[i]][1].push_back(s2[i-1]);
    }
    bool ok=true;
    for (int i = 1; i <= n; ++i) {
      if (par[i] == i) {
        sort(v[i][0].begin(), v[i][0].end());
        sort(v[i][1].begin(), v[i][1].end());
       // cout<<"i="<<i<<" "<<v[i][0]<<" "<<v[i][1]<<endl;
        if (v[i][0] != v[i][1]) {
          ok=false;
          break;
        }
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
