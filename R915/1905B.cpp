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
#define N 200005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int deg[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      deg[i]=0;
    }
    for (int i = 1; i < n; ++i) {
      int u,v;
      scanf("%d%d",&u,&v);
      deg[u]++;
      deg[v]++;
    }
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
      if (deg[i] == 1) cnt++;
    }
    printf("%d\n", (cnt+1)/2);
  }
  return 0;
}
