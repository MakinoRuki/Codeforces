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
#define N 52
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
int t;
int n, m;
vector<string> mp;
bool vis[N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void bfs(int x, int y) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      vis[i][j] = false;
    }
  }
  if (mp[x][y] == '#') {
    return ;
  }
  vis[x][y] = true;
  queue<int> q;
  q.push(x*m+y);
  while(!q.empty()) {
    int cur=q.front();
    q.pop();
    int cx = cur/m;
    int cy = cur%m;
    for (int d = 0; d < 4; ++d) {
      int nx = cx+dx[d];
      int ny = cy+dy[d];
      if (nx >=0 && nx < n && ny >= 0 && ny < m && mp[nx][ny] != '#') {
        if (!vis[nx][ny]) {
          vis[nx][ny] = true;
          q.push(nx*m+ny);
        }
      }
    }
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n>>m;
    mp.clear();
    int g=0, b=0;
    for (int i = 0; i < n; ++i) {
      string s;
      cin>>s;
      mp.push_back(s);
      for (int j = 0; j < m; ++j) {
        if (mp[i][j] == 'G') g++;
        else if (mp[i][j] == 'B') b++;
      }
    }
    // if (!b) {
    //   cout<<"Yes"<<endl;
    // } else {
    //   if (!g) cout<<"Yes"<<endl;
    //   else {
        bfs(n-1, m-1);
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < m; ++j) {
            if (mp[i][j] == 'B') {
              for (int d = 0; d < 4; ++d) {
                int ni = i+dx[d];
                int nj = j+dy[d];
                if (ni>=0 && ni < n && nj >=0 && nj < m && vis[ni][nj] && mp[ni][nj] == '.') {
                  mp[ni][nj] = '#';
                }
              }
            }
          }
        }
        bfs(n-1, m-1);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < m; ++j) {
            if (mp[i][j] == 'G' && !vis[i][j]) ok =false;
            else if (mp[i][j] == 'B' && vis[i][j]) ok = false;
          }
        }
        if (!ok) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    //   }
    // }
  }
  return 0;
}
