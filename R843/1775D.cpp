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
#define N 300005
#define M 80
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, q;
int k;
int t;
int a[N];
int x, y;
bool pr[N];
vector<int> ids[N];
vector<int> edges[N];
vector<int> ps[N];
int dis[N];
int pre[N];
int pre2[N];
int bfs(int sx, int sy) {
  for (int i = 0; i < N; ++i) {
    dis[i] = inf;
  }
  queue<pair<int,int>> q;
  for (int i = 0; i < ps[sx].size(); ++i) {
    int p = ps[sx][i];
    dis[p] = 1;
    pre[p] = -1;
    pre2[p] = sx;
    q.push(make_pair(p, sx));
  }
  while(!q.empty()) {
    auto pr = q.front();
    q.pop();
    int p = pr.first;
    int id = pr.second;
  //  cout<<"p="<<o
    for (int i = 0; i < edges[p].size(); ++i) {
      int id2 = edges[p][i];
      if (id2 == sy) {
        return p;
      }
      for (int j = 0; j < ps[id2].size(); ++j) {
        int p2 = ps[id2][j];
        if (dis[p2] > dis[p]+1) {
          dis[p2] = dis[p] + 1;
          pre[p2] = p;
          pre2[p2] = id2;
          q.push(make_pair(p2, id2));
        }
      }
    }
  }
  return -1;
}
int main() {
  cin>>n;
  map<int,int> mp;
  mp.clear();
  memset(pr, true, sizeof(pr));
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  cin>>x>>y;
  ids[a[x]].push_back(x);
  ids[a[y]].push_back(y);
  mp[a[x]] = x;
  mp[a[y]] = y;
  if (x == y) {
    puts("1");
    printf("%d\n", x);
    return 0;
  }
  for (int i =1 ; i <= n; ++i) {
    if (mp.find(a[i]) == mp.end()) {
      ids[a[i]].push_back(i);
      mp[a[i]] = i;
    }
  }
  for (int i = 2; i < N; ++i) {
    if (pr[i]) {
      for (int j = i; j < N; j += i) {
        if (ids[j].empty()) continue;
        for (int k = 0; k < ids[j].size(); ++k) {
          edges[i].push_back(ids[j][k]);
          ps[ids[j][k]].push_back(i);
        }
      }
    }
  }
  int p = bfs(x, y);
  if (p < 0) {
    puts("-1");
    return 0;
  }
  printf("%d\n", dis[p]+1);
  vector<int> ans;
  ans.clear();
  int cur = p;
  while(cur >= 0) {
    ans.push_back(pre2[cur]);
    cur = pre[cur];
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d ", ans[i]);
  }
  cout<<y<<endl;
  return 0;
}
