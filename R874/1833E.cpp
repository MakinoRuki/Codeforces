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
int par[N];
int find(int u) {
  return u == par[u] ? u : par[u] = find(par[u]);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    set<pair<int,int>> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      par[i] = i;
      scanf("%d", &a[i]);
      if (i < a[i]) {
        ss.insert(make_pair(i, a[i]));
      } else {
        ss.insert(make_pair(a[i], i));
      }
    }
    vector<pair<int,int>> v(ss.begin(), ss.end());
    int cnt=0;
    for (int i = 0; i < v.size(); ++i) {
      int x = v[i].first;
      int y = v[i].second;
      int px = find(x);
      int py = find(y);
      if (px != py) {
        par[px] = py;
      } else {
        cnt++;
      }
    }
    int tot=0;
    for (int i = 1; i <= n; ++i) {
      par[i] = find(i);
      if (par[i] == i) tot++;
    }
    if (cnt == tot) {
      printf("%d %d\n", tot, tot);
    } else {
      printf("%d %d\n", cnt+1, tot);
    }
  }
  return 0;
}
