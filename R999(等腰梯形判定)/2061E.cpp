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
#define N 100005
#define M 1005
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
int b[N];
int ma[N][11];
int res[1<<11];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    ll ans=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ans += a[i];
    }
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &b[i]);
    }
    for (int i = 0; i < (1<<m); ++i) {
      int st=(1<<30)-1;
      for (int j = 0; j < m; ++j) {
        if ((1<<j)&i) {
          st &= b[j+1];
        }
      }
      res[i] = st;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        ma[i][j] = 2*inf;
      }
      for (int j = 0; j < (1<<m); ++j) {
        int cnt = __builtin_popcount(j);
        ma[i][cnt] = min(ma[i][cnt], res[j]&a[i]);
      }
    }
  //  cout<<"v="<<ma[1][0]<<" "<<ma[1][1]<<" "<<ma[1][2]<<" "<<ma[1][3]<<endl;
    priority_queue<pair<ll, pair<int,int>>> pq;
    for (int i = 1; i <= n; ++i) {
      pq.push(make_pair(a[i]-ma[i][1], make_pair(i, 1)));
    }
    for (int i = 1; i <= k; ++i) {
      if (pq.empty()) break;
      auto pr = pq.top();
      pq.pop();
      ll v = pr.first;
    //  cout<<"i="<<i<<" "<<v<<endl;
      int x = pr.second.first;
      int y = pr.second.second;
      if (v < 0) break;
      ans -= v;
      if (y+1<=m) {
        pq.push(make_pair(ma[x][y]-ma[x][y+1], make_pair(x, y+1)));
      }
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
