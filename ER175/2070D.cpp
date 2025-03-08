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
#define N 500005
#define M 750
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
int dep[N];
int p[N];
int cnt[N];
vector<int> ps[N];
ll ans[N];
void dfs(int u, int d) {
    dep[u] = d;
    for (auto v : edges[u]) {
        dfs(v, d+1);
    }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    cnt[0]=0;
  //  printf("%lld\n", (k-1)/2+1);
    for (int i = 1; i <= n; ++i) {
        edges[i].clear();
        cnt[i]=0;
        ps[i].clear();
        ans[i]=0LL;
    }
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &p[i]);
        edges[p[i]].push_back(i);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
        cnt[dep[i]]++;
        ps[dep[i]].push_back(i);
    }
    ll res=0LL;
    ll pre=0LL;
    for (int i = n; i >= 1; --i) {
        if (cnt[i] > 0) {
            ll tot=0LL;
            for (int j = 0; j < ps[i].size(); ++j) {
                int u = ps[i][j];
                ll sum=0LL;
                for (int v : edges[u]) {
                    sum = (sum + ans[v]) % mod2;
                }
                ll tmp = (pre - sum + mod2) % mod2;
                tmp = (tmp + 1) % mod2;
                ans[u] = tmp;
                tot = (tot + tmp) % mod2;
            }
            pre = tot;
        }
    }
    for (int u : edges[1]) {
        res = (res + ans[u]) % mod2;
    }
    res = (res+1) % mod2;
    printf("%lld\n", res);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
