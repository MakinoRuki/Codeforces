#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 105
#define N 100
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, m, k;
vector<string> mat;
bool vis[M][M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    mat.clear();
    for (int i = 0; i < n; ++i) {
      string s;
      cin>>s;
      mat.push_back(s);
    }
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        vis[i][j] = false;
      }
    }
    bool ok=true;
    for (int i = n-1; i >=0; --i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] == '*' && i-1>=0 && j-1>=0 && mat[i-1][j-1]=='*' && j+1<m && mat[i-1][j+1]=='*') {
          int cx=i;
          int cy=j;
          int d;
          vector<pair<int,int>> tmp;
          tmp.clear();
          for (d = 1; ; ++d) {
            if (cx-d>=0 && cy-d>=0 && cy+d<m && mat[cx-d][cy-d]=='*' && mat[cx-d][cy+d]=='*') {
              tmp.push_back(make_pair(cx-d, cy-d));
              tmp.push_back(make_pair(cx-d, cy+d));
            } else {
              break;
            }
          }
          d--;
          if (d >= k) {
            vis[cx][cy]=true;
            for (int i = 0; i < tmp.size(); ++i) {
              vis[tmp[i].first][tmp[i].second]=true;
            }
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j]=='*' && !vis[i][j]) {
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
