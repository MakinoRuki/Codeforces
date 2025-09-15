
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
#define M 5002
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
bitset<N> dp[2];
bitset<N> cc;
int cnt[N];
int mnd;
void dfs(int u, int d) {
  cnt[d]++;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    dfs(v, d+1);
  }
  if ((int)edges[u].size()==0) {
    mnd = min(mnd, d);
  }
}
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
      cnt[i]=0;
    }
    for (int i = 2; i <= n; ++i) {
      int p;
      scanf("%d", &p);
      edges[p].push_back(i);
    }
    mnd=inf;
    dfs(1,1);
    dp[0].reset(), dp[1].reset();
    cc.reset();
    dp[0][0]=true;
    for (int i = 0; i <= k; ++i) {
      cc[i]=true;
    }
    int ans=0;
    int cur=0;
    int tot=0;
    for (int i = 0; i < mnd; ++i) {
      int now=i&1;
      tot += cnt[i+1];
      while(cur < tot+k-n) {
        cc[cur]=false;
        cur++;
      }
      dp[now^1] = ((dp[now]<<cnt[i+1])|dp[now]) & cc;
      if (dp[now^1].count()) {
        ans++;
      } else {
        break;
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
