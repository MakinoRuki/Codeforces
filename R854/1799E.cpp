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
#include <bitset>
#define N 2000005
#define M 60
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k;
int t;
int a[N];
int l[N], r[N];
int u[N], d[N];
int rn[N], cn[N];
bool vis[M][M];
int idx[M][M];
vector<string> mp;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void solve(int x, int y, int dx, int dy) {
  int cx=x,cy=y;
  if (mp[cx-1][cy-1]=='#') return;
  while(true) {
    mp[cx-1][cy-1]= '#';
    cy += dy;
    if (cy<1||cy>m||mp[cx-1][cy-1]=='#') {
      cx+=dx;
      cy=y;
      if (cx<1||cx>n||mp[cx-1][cy-1]=='#') {
        break;
      }
    }
  }
}
void bfs(int x, int y, int cur, int& ll, int& rr, int& uu, int& dd) {
  queue<pair<int,int>> q;
  q.push(make_pair(x,y));
  idx[x][y]=cur;
  while(!q.empty()) {
    auto pr = q.front();
    q.pop();
    int cx=pr.first;
    int cy=pr.second;
    ll=min(ll, cy);
    rr=max(rr, cy);
    uu=min(uu, cx);
    dd=max(dd, cx);
    for (int i=0;i<4;++i) {
      int nx=cx+dx[i];
      int ny=cy+dy[i];
      if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx-1][ny-1]=='#'&&!idx[nx][ny]) {
        q.push(make_pair(nx,ny));
        idx[nx][ny]=cur;
      }
    }
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    mp.clear();
    for (int i = 1; i <= n; ++i) {
      l[i] = m+1, r[i] = 0;
      rn[i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
      u[i] = n+1, d[i]=0;
      cn[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      string s;
      cin>>s;
      mp.push_back(s);
      for (int j = 1; j <= m; ++j) {
        vis[i][j]=false;
        idx[i][j]=0;
        if (s[j-1] == '#') {
          rn[i]++;
          cn[j]++;
          l[i] = min(l[i], j);
          r[i]=max(r[i], j);
          u[j] = min(u[j], i);
          d[j] = max(d[j], i);
        }
      }
    }
    queue<pair<int,int>> q;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (mp[i-1][j-1] == '.') {
          if ((i>=u[j] && i <= d[j]) || (j>=l[i] && j <= r[i])) {
            q.push(make_pair(i,j));
            vis[i][j]=true;
          }
        }
      }
    }
    while(!q.empty()) {
      auto pr = q.front();
      q.pop();
      int x = pr.first;
      int y = pr.second;
      mp[x-1][y-1] = '#';
      l[x] = min(l[x], y);
      r[x] = max(r[x], y);
      u[y] = min(u[y], x);
      d[y] = max(d[y], x);
      for (int i = 0; i < 4; ++i) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx >= 1 && nx <=n && ny>=1 && ny<=m && mp[nx-1][ny-1] == '.' && !vis[nx][ny]) {
          if ((nx>=u[ny] && nx <=d[ny]) || (ny>=l[nx] && ny<=r[nx])) {
            q.push(make_pair(nx, ny));
            vis[nx][ny]=true;
          }
        }
      }
    }
    int l1=m+1,r1=0,u1=n+1,d1=0;
    int l2=m+1,r2=0,u2=n+1,d2=0;
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (mp[i-1][j-1] == '#') {
          if (!idx[i][j]) {
            ++cur;
            if (cur==1) {
              bfs(i,j,cur,l1,r1,u1,d1);
            } else {
              bfs(i,j,cur,l2,r2,u2,d2);
            }
          }
        }
      }
    }
    if (l2 <= m) {
      if (r1 < l2 && d1 < u2) {
        //cout<<"???"<<endl;
        for (int j=r1+1;j<=l2; ++j) {
          mp[d1-1][j-1]='#';
        }
        for (int i=d1;i<u2;++i) {
          mp[i-1][l2-1]='#';
        }
        solve(d1, r1, -1, -1);
        solve(u2, l2, 1, 1);
      } else if (r1 < l2 && u1 > d2) {
        for (int i = d2; i < u1; ++i) {
          mp[i-1][r1-1]='#';
        }
        for (int j = r1; j<l2; ++j) {
          mp[d2-1][j-1]='#';
        }
        solve(u1, r1, 1, -1);
        solve(d2, l2, -1, 1);
      } else if (l1 > r2 && d1 < u2) {
       // cout<<">>>"<<endl;
        for (int i = d1; i<u2; ++i) {
          mp[i-1][r2-1]='#';
        }
        for (int j = r2; j< l1; ++j) {
          mp[d1-1][j-1]='#';
        }
        solve(d1, l1, -1, 1);
        solve(u2, r2, 1, -1);
      } else {
        for (int i = d2+1; i <= u1; ++i) {
          mp[i-1][l1-1] ='#';
        }
        for (int j = r2; j < l1; ++j) {
          mp[d2-1][j-1]='#';
        }
        solve(d2, r2, -1, -1);
        solve(u1, l1, 1, 1);
      }
    }
    for (int i = 1; i <= n; ++i) {
      cout<<mp[i-1]<<endl;
    }
    cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

