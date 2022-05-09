#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <list>
#include <random>
#define N 200005
#define M 502
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int p[N];
bool vis[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      vis[i] = false;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);
      vis[p[i]] = true;
    }
    if (n == 1) {
      puts("1");
      puts("1");
      puts("1");
      continue;
    }
    vector<vector<int>> ans;
    ans.clear();
    vector<int> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) {
        v.push_back(i);
      }
    }
    for (int i = 1; i <= n; ++i) {
      vis[i] = false;
    }
    for (auto x : v) {
      int cur = x;
      vector<int> tmp;
      tmp.clear();
      while(true) {
        tmp.push_back(cur);
        vis[cur] = true;
        if (cur ==p[cur] || vis[p[cur]]) {
          break;
        }
        cur = p[cur];
      }
      ans.push_back(tmp);
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d\n", (int)ans[i].size());
      for (int j= ans[i].size()-1; j >= 0; --j) {
        printf("%d", ans[i][j]);
        if (j > 0) cout<<" ";
        else cout<<endl;
      }
    }
  }
  return 0;
}
