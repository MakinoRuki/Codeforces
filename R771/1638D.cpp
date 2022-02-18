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
#define N 1005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N][N];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool vis[N][N];
int check(int x, int y) {
  set<int> ss;
  ss.clear();
  if (a[x][y] > 0) ss.insert(a[x][y]);
  if (a[x+1][y] > 0) ss.insert(a[x+1][y]);
  if (a[x][y+1] > 0) ss.insert(a[x][y+1]);
  if (a[x+1][y+1] > 0) ss.insert(a[x+1][y+1]);
  if (ss.empty()) return 0;
  if (ss.size() > 1) return -1;
  return (*ss.begin());
}
int main() {
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
      vis[i][j] = false;
    }
  }
  queue<pair<int,int>> q;
  for (int i = 1; i < n; ++i) {
    for (int j =1; j < m; ++j) {
      int res = check(i, j);
      if (res >= 0) {
        q.push(make_pair(i, j));
        vis[i][j] = true;
      }
    }
  }
  vector<pair<pair<int,int>, int>> ans;
  ans.clear();
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    int x = cur.first;
    int y = cur.second;
    int res = check(x, y);
    if (res > 0) {
      ans.push_back(make_pair(make_pair(x,y), res));
    } else {
      ans.push_back(make_pair(make_pair(x, y), 1));
    }
    a[x][y] = 0;
    a[x+1][y] = 0;
    a[x][y+1] = 0;
    a[x+1][y+1] = 0;
    for (int d = 0; d < 8; ++d) {
      int nx = x+dx[d];
      int ny= y+dy[d];
      if (nx >= 1 && nx < n && ny >= 1 && ny < m) {
        int res2 = check(nx, ny);
        if (res2 >= 0 && !vis[nx][ny]) {
          q.push(make_pair(nx, ny));
          vis[nx][ny] = true;
        }
      }
    }
  }
  if (ans.size() < (m-1)*(n-1)) {
    puts("-1");
  } else {
    printf("%d\n", (int)ans.size());
    for (int i = ans.size()-1; i >= 0; --i) {
      printf("%d %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second);
    }
  }
  return 0;
}
