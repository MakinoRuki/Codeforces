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
#define M 10
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n,m,p;
int s[M];
vector<string> mp;
int vis[N][N];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void bfs() {
  memset(vis, 0, sizeof(vis));
  queue<int> q[M][2];
  for (int i = 1; i <= p; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        if (mp[j][k]-'0' == i) {
          q[i][0].push(j*m+k);
          vis[j][k] = i;
        }
      }
    }
  }
  while(true) {
    bool found=false;
    for (int i = 1; i <= p; ++i) {
      int now;
      if (!q[i][0].empty()) now = 0;
      else if (!q[i][1].empty()) now = 1;
      else {
        continue;
      }
      found=true;
      for (int ds=1; ds <= s[i]; ++ds) {
        if (q[i][now].empty()) break;
        while(!q[i][now].empty()) {
          int cur = q[i][now].front();
          q[i][now].pop();
          int x = cur/m;
          int y = cur%m;
          for (int d = 0; d < 4; ++d) {
            int nx = dx[d]+x;
            int ny = y+dy[d];
            if (nx>=0&&nx<n&&ny>=0&&ny<m&&mp[nx][ny]!='#'&&!vis[nx][ny]) {
              vis[nx][ny] = i;
              q[i][now^1].push(nx*m+ny);
            }
          }
        }
        now ^= 1;
      }
    }
    if (!found) break;
  }
}
int main() {
  cin>>n>>m>>p;
  for (int i = 1; i <= p; ++i) {
    scanf("%d", &s[i]);
  }
  mp.clear();
  for (int i = 0; i < n; ++i) {
    string s;
    cin>>s;
    mp.push_back(s);
  }
  bfs();
  for (int i = 1; i <= p; ++i) {
    int cnt=0;
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        if (vis[j][k] == i) cnt++;
      }
    }
    printf("%d", cnt);
    if (i < p) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
