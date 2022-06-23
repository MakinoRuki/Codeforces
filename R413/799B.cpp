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
#define M 3000000
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int d;
int p[N];
int a[N];
int b[N];
int c[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
    
  // }
  cin>>n;
  map<int, set<pair<int,int>>> mp;
  mp.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    mp[a[i]].insert(make_pair(p[i], i));
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    if (b[i] != a[i]) {
      mp[b[i]].insert(make_pair(p[i], i));
    }
  }
  cin>>m;
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &c[i]);
    if (mp[c[i]].empty()) {
      printf("-1");
    } else {
      auto pr = *mp[c[i]].begin();
      printf("%d", pr.first);
      int id = pr.second;
      mp[a[id]].erase(make_pair(p[id], id));
      mp[b[id]].erase(make_pair(p[id], id));
    }
    if (i < m) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
