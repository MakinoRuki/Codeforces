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
#define N 1002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m, t;
vector<string> mt;
int dis[N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool vis[N*N];
void bfs(vector<int>& ss) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      dis[i][j] = 1000000000;
    }
  }
  queue<int> q;
  memset(vis, false, sizeof(vis));
  for (int i = 0; i < ss.size(); ++i) {
    dis[ss[i]/m][ss[i]%m] = 1;
    vis[ss[i]] = true;
    q.push(ss[i]);
  }
  while(!q.empty()) {
    int cur=q.front();
    q.pop();
    int x = cur/m;
    int y = cur%m;
    for (int d = 0; d < 4; ++d) {
      int nx = x+dx[d];
      int ny = y+dy[d];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (dis[nx][ny] > dis[x][y]+1) {
          dis[nx][ny] = dis[x][y]+1;
          if (!vis[nx*m+ny]) {
            vis[nx*m+ny] = true;
            q.push(nx*m+ny);
          }
        }
      }
    }
  }
}
int main() {
  cin>>n>>m>>t;
  mt.clear();
  for (int i = 0; i < n; ++i) {
    string s;
    cin>>s;
    mt.push_back(s);
  }
  vector<int> ss;
  ss.clear();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int d;
      for (d = 0; d < 4; ++d) {
        int x = i+dx[d];
        int y = j+dy[d];
        if (x >= 0 && x < n && y >= 0 && y < m && mt[x][y] == mt[i][j]) {
          break;
        }
      }
      if (d < 4) {
        ss.push_back(i*m+j);
      }
    }
  }
  bfs(ss);
  for (int i = 1; i <= t; ++i) {
    int x,y;
    ll p;
    scanf("%d%d%lld", &x, &y, &p);
    int ds = dis[x-1][y-1];
    if (ds >= 1000000000) {
      cout<<mt[x-1][y-1]<<endl;
      continue;
    }
    if (ds > p) {
      cout<<mt[x-1][y-1]<<endl;
    } else {
      ll dt = p-ds;
      if (dt%2==0) {
        if (mt[x-1][y-1]=='1') puts("0");
        else puts("1");
      } else {
        cout<<mt[x-1][y-1]<<endl;
      }
    }
  }
  return 0;
}
