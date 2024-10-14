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
int a[N];
vector<pair<int,int>> sg[11][11];
int par[N];
int find(int x) {
  return x == par[x] ? x : par[x] = find(par[x]);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      par[i] = i;
    }
    for (int i = 0; i <= 10; ++i) {
      for (int j = 0; j <= 10; ++j) {
        sg[i][j].clear();
      }
    }
    for (int i = 1; i <= m; ++i) {
      int x,d,k;
      scanf("%d%d%d", &x, &d, &k);
      sg[x%d][d].push_back(make_pair(x, x+d*k));
    }
    for (int i = 0; i < 10; ++i) {
      for (int j = 1; j <= 10; ++j) {
        if (sg[i][j].empty()) continue;
        sort(sg[i][j].begin(), sg[i][j].end());
        vector<pair<int,int>> v;
        v.clear();
        int l = sg[i][j][0].first, r = sg[i][j][0].second;
        for (int p = 1; p < sg[i][j].size(); ++p) {
          int nl = sg[i][j][p].first, nr = sg[i][j][p].second;
          if (nl <= r && nr >= l) {
            l = min(l, nl);
            r = max(r, nr);
          } else {
            v.push_back(make_pair(l, r));
            l = nl, r = nr;
          }
        }
        v.push_back(make_pair(l, r));
        sg[i][j] = v;
      }
    }
    for (int i = 0; i < 10; ++i) {
      for (int j = 1; j <= 10; ++j) {
        if (sg[i][j].empty()) continue;
        for (auto itr : sg[i][j]) {
          int l = itr.first, r = itr.second;
          for (int p = l; p < r; p += j) {
            //cout<<p<<" "<<p+j<<endl;
            int p1 = find(p);
            int p2 = find(p+j);
            if (p1 != p2) {
              par[p1] = p2;
            }
          }
        }
      }
    }
    int ans=0;
    for (int i = 1; i <= n; ++i) {
      par[i] = find(i);
      if (i == par[i]) ans++;
    }
    printf("%d\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

