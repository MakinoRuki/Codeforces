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
#include <chrono>
#define N 200005
#define M 1002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
vector<int> edges[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u,v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
      if (i == 1) cnt[i] = (int)edges[i].size();
      else cnt[i] = (int)edges[i].size()-1;
    }
    set<pair<int,int>> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      ss.insert(make_pair(cnt[i], i));
    }
    int ans=0;
    for (int i = 1; i <= n; ++i) {
      vector<int> v;
      v.clear();
      for (int j = 0; j < edges[i].size(); ++j) {
        int u = edges[i][j];
        int tmp=0;
        if (i == 1 || u == 1) {
          ans = max(ans, cnt[i]+cnt[u]-1);
        } else {
          ans = max(ans, cnt[i]+cnt[u]);
        }
        ss.erase(make_pair(cnt[u], u));
        v.push_back(u);
      }
      ss.erase(make_pair(cnt[i], i));
      if (!ss.empty()) {
        int vv = (*ss.rbegin()).second;
        if (i == 1 || vv == 1) {
          ans = max(ans, cnt[i] + (*ss.rbegin()).first);
        } else {
          ans = max(ans, cnt[i] + (*ss.rbegin()).first+1);
        }
      }
      ss.insert(make_pair(cnt[i], i));
      for (auto x : v) {
        ss.insert(make_pair(cnt[x], x));
      }
    }
    printf("%d\n", ans);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
