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
#define M 202
#define N 20000
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int par[N];
int cnt[N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0,0,-1,1};
vector<int> xs[N], ys[N];
int find(int x) {
  return x== par[x] ? x : par[x] = find(par[x]);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      cin>>s;
      for (int j = 0; j < m; ++j) {
        a[i*m+j] = s[j]-'0';
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        par[i*m+j] = i*m+j;
        cnt[i*m+j] = 1;
        xs[i*m+j].clear();
        ys[i*m+j].clear();
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!a[i*m+j]) continue;
        for (int d = 0; d < 4; ++d) {
          int ni = i + dx[d];
          int nj = j + dy[d];
          if (ni >=0 &&  ni < n && nj >= 0 && nj < m && a[ni*m+nj]) {
            int px = find(i * m + j);
            int py = find(ni * m + nj);
            if (px != py) {
              par[px] = py;
              cnt[py] += cnt[px];
            }
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i * m + j]) {
          int p =find(i * m + j);
          xs[p].push_back(i);
          ys[p].push_back(j);
        }
      }
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i * m + j] && par[i * m + j] == i * m + j) {
          sort(xs[i * m + j].begin(), xs[i * m + j].end());
          sort(ys[i * m + j].begin(), ys[i * m + j].end());
          int tot = (xs[i * m + j].back() - xs[i * m + j][0] + 1);
          tot *= (ys[i * m + j].back() - ys[i * m + j][0] + 1);
          if (tot != cnt[i * m + j]) {
            ok=false;
            break;
          }
        }
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
