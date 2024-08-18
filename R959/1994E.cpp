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
#define N 1000005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
vector<int> edges[N];
int cnt[N];
int dfs(int u) {
  int res=1;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    res += dfs(v);
  }
  return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) {
      scanf("%d", &n);
      for (int j = 1; j <= n; ++j) {
        edges[j].clear();
      }
      for (int j =2; j <= n; ++j) {
        int p;
        scanf("%d", &p);
        edges[p].push_back(j);
      }
      cnt[i] = dfs(1);
    }
    int ans=0;
    for (int i = 20; i >= 0; --i) {
      int num=0;
      for (int j = 1; j <= k; ++j) {
        if ((1<<i) & cnt[j]) {
          num++;
        }
      }
      if (num > 0) {
        ans |= (1<<i);
        if (num > 1) {
          ans |= (1<<i)-1;
          break;
        }
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
