
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
#define N 600005
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
int b[N];
int deg[N];
vector<int> edges[N];
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      deg[i]=0;
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u,v,x,y;
      scanf("%d%d%d%d", &u, &v, &x, &y);
      if (x > y) {
        deg[v]++;
        edges[u].push_back(v);
      } else {
        deg[u]++;
        edges[v].push_back(u);
      }
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
      if (deg[i] == 0) {
        q.push(i);
      }
    }
    int cur=n;
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      a[u] = cur;
      cur--;
      for (auto v : edges[u]) {
        deg[v]--;
        if (deg[v] == 0) {
          q.push(v);
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", a[i]);
    }
    cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0));
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
