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
#define M 21
#define N 2002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int q;
vector<string> mat;
int dp[N][N];
int vis[N][N];
void getxy(int& x, int& y, char c) {
  if (c == 'R') {
    y++;
  } else if (c == 'L') {
    y--;
  } else if (c == 'U') {
    x--;
  } else {
    x++;
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    mat.clear();
    for (int i = 0; i < n; ++i) {
      string s;
      cin>>s;
      mat.push_back(s);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        dp[i][j] = -1;
        vis[i][j] = -1;
      }
    }
    int d = 0, x = 1, y = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (dp[i][j] < 0) {
          vector<pair<int,int>> ps;
          ps.clear();
          int cnt=0;
          int cx=i, cy=j;
          while(true) {
            ps.push_back(make_pair(cx,cy));
            vis[cx][cy] =  cnt++;
            int nx=cx,ny=cy;
            getxy(nx, ny, mat[cx][cy]);
            cx = nx, cy = ny;
            if (cx >= 0 && cx < n && cy >= 0 && cy < m && dp[cx][cy] < 0 && vis[cx][cy]<0) {
              continue;
            } else {
              break;
            }
          }
        //  if (i == 0 && j == 1) cout<<"cx"<<cx<<" "<<cy<<" "endl;
          if ((cx < 0) || (cx >= n) || (cy<0) || (cy>=m)) {
            for (int k = 0; k < ps.size(); ++k) {
              dp[ps[k].first][ps[k].second] = cnt-vis[ps[k].first][ps[k].second];
            }
          } else if (dp[cx][cy] >= 0) {
            for (int k = 0; k < ps.size(); ++k) {
              dp[ps[k].first][ps[k].second] = dp[cx][cy] + cnt-vis[ps[k].first][ps[k].second];
            }
          } else {
            int len = cnt-vis[cx][cy];
            for (int k = 0; k < ps.size(); ++k) {
              int xx = ps[k].first;
              int yy = ps[k].second;
              if (vis[xx][yy] < vis[cx][cy]) {
                dp[xx][yy] = vis[cx][cy] - vis[xx][yy] + len;
              } else {
                dp[xx][yy] = len;
              }
            }
          }
       //   cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
          if (dp[i][j] > d) {
            d = dp[i][j];
            x = i, y = j;
          }
        }
      }
    }
    printf("%d %d %d\n", x+1, y+1, d);
  }  
  return 0;
}
