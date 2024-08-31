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
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int L[N], R[N];
int ans;
string s;
void dfs(int u, int dt) {
  if (!L[u] && !R[u]) {
    ans=min(ans, dt);
    return;
  }
  if (L[u]) {
    int c=0;
    if (s[u-1] != 'L') {
      c++;
    }
    dfs(L[u], dt+c);
  }
  if (R[u]) {
    int c=0;
    if (s[u-1] != 'R') {
      c++;
    }
    dfs(R[u], dt+c);
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    cin>>s;
    for (int i = 1; i <= n; ++i) {
      scanf("%d %d", &L[i], &R[i]);
    }
    ans=inf;
    dfs(1,0);
    printf("%d\n", ans);
  }
  return 0;
}
