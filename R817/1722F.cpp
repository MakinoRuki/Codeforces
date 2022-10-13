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
#define N 52
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int par[M];
vector<int> ids[M];
int mat[N][N];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int find(int x) {
  return x==par[x] ? x : par[x] = find(par[x]);
}
bool check(vector<int>& v) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (i != j) {
        int dx = abs(v[i]/m-v[j]/m);
        int dy = abs(v[i]%m-v[j]%m);
        if (dx > 1 || dy > 1) return false;
      }
    }
  }
  return true;
}
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i= 0; i <= n*m; ++i) {
      par[i] = i;
      ids[i].clear();
    }
    for (int i = 0; i < n; ++i) {
      string s;
      cin>>s;
      for (int j = 0; j < m; ++j) {
        if (s[j] == '*') {
          mat[i][j] = 1;
        } else mat[i][j] = 0;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j]) {
          int px = find(i * m + j);
          for (int d = 0; d < 8; ++d) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if (ni >= 0 && ni < n && nj >=0 && nj < m && mat[ni][nj]) {
              int py = find(ni * m + nj);
              if (px != py) {
                par[px] = py;
              }
            }
          }
        }
      }
    }
    for (int i = 0; i < n * m; ++i) {
      if (mat[i/m][i%m]) {
        int px = find(i);
        ids[px].push_back(i);
      }
    }
    bool ok = true;
    for (int i = 0; i < n * m; ++i) {
      // if (ids[i].size() > 0) {
      //   cout<<"x="<<i<<" "<<i/m<<" "<<i%m<<" "<<ids[i].size()<<endl;
      // }
      if (ids[i].size() > 0 && ids[i].size() != 3) {
        ok=false;
        break;
      } else if (ids[i].size() == 3) {
        if (!check(ids[i])) {
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
