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
#define N 150002
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int par[N];
int nxt[N], ed[N];
int find(int u) {
  return u==par[u] ? u : par[u] = find(par[u]);
}
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    par[i] = i;
    ed[i] = i;
    nxt[i] = i;
  }
  for (int i = 1; i < n; ++i) {
    int x,y;
    scanf("%d%d", &x, &y);
    int px = find(x);
    int py = find(y);
    par[py] = px;
    nxt[ed[px]] = py;
    ed[px] = ed[py];
  }
  int st = find(1);
  for (int i = 1; i <= n; ++i) {
    printf("%d", st);
    st = nxt[st];
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
