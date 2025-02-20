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
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int ans[N];
vector<pair<int,int>> es[N];
bool vis[N];
vector<pair<pair<int,int>, int>> qs;
int main() {
  cin>>n>>q;
  memset(ans, 0, sizeof(ans));
  qs.clear();
  for (int i = 1; i <= n; ++i) {
    es[i].clear();
  }
  for (int i = 1; i <= q; ++i) {
    int x,y,z;
    scanf("%d%d%d", &x, &y, &z);
    es[x].push_back(make_pair(y,z));
    es[y].push_back(make_pair(x,z));
    qs.push_back(make_pair(make_pair(x,y),z));
  }
  for (int i = 29; i >= 0; --i) {
    for (int j = 1; j <= n; ++j) {
      vis[j]=false;
    }
    for (int j = 0; j < qs.size(); ++j) {
      int x=qs[j].first.first;
      int y=qs[j].first.second;
      int z=((1<<i)&qs[j].second)>0;
      if (!z) {
        vis[x]=true;
        vis[y]=true;
      }
    }
    for (int j = 1; j <= n; ++j) {
      if (!vis[j]) {
        vis[j]=true;
        for (int k = 0; k < es[j].size(); ++k) {
          int y = es[j][k].first;
          int z= ((1<<i)&es[j][k].second)>0;
          if (y == j) {
            if (z) ans[j] |= (1<<i);
          }
        }
        for (int k = 0; k < es[j].size(); ++k) {
          int y = es[j][k].first;
          int z= ((1<<i)&es[j][k].second)>0;
          if (y == j) continue;
          if (vis[y] && z && !((1<<i)&ans[y])) {
            ans[j] |= (1<<i);
          }
        }
      }
      //if (i==29) cout<<"j="<<j<<" "<<(int)qs[j].size()<<" "<<ans[j]<<endl;
    }
    // if (i >= 2) {
    //   for (int j = 1; j <= n; ++j) {
    //     cout<<"j="<<j<<" "<<ans[j]<<endl;
    //   }
    // }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", ans[i]);
  }
  cout<<endl;
  return 0;
}
