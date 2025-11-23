/* 小于等于k的值先全部加进来，如果能连通那么无论如何可以保留最接近k的那条边作为max。
然后把大于k的边一条条check，能改变连通性的必须加进来否则不要，然后一直加到连通就停止。
*/

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
#define N 300005
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
int par[N];
vector<pair<int, pair<int,int>>> es;
int find(int u) {
    return u == par[u] ? u : par[u] = find(par[u]);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      scanf("%d%d%d", &n, &m, &k);
      es.clear();
      int cnt=n;
      for (int i = 1; i <= n; ++i) {
        par[i] = i;
      }
      for (int i = 1; i <= m; ++i) {
        int u,v,w;
        scanf("%d%d%d", &u, &v, &w);
        es.push_back(make_pair(w, make_pair(u, v)));
      }
      sort(es.begin(), es.end());
      ll ans=(1LL<<61)-1;
      for (auto pr : es) {
        int w = pr.first;
        int u = pr.second.first;
        int v = pr.second.second;
        int pu=find(u);
        int pv=find(v);
        if (pu != pv) {
            par[pu] = pv;
            cnt--;
        }
        if (w <= k) {
            if (cnt == 1) {
                ans = min(ans, (ll)k-w);
            }
        } else {
            if (cnt == 1) ans = min(ans, (ll)w-k);
            break;
        }
      }
      if (cnt > 1) {
        for (int i = 1; i <= n; ++i) {
            par[i] = i;
        }
        ll tot=0LL;
        cnt=n;
        for (auto pr : es) {
            int w = pr.first;
            int u = pr.second.first;
            int v = pr.second.second;
            int pu=find(u);
            int pv=find(v);
            if (pu != pv) {
                par[pu] = pv;
                cnt--;
                if (w > k) {
                  tot += w-k; 
                }
            }
            
            if (cnt == 1) {
                break;
            }
        }
        if (cnt == 1) ans = min(ans, tot);
      }
      printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
