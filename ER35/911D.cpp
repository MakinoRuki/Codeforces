#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 1505
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, q, k;
int t;
int a[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d%d", &n, &m);
    
  // }
  cin>>n;
  int tot=0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i-1; j >= 1; --j) {
      if (a[j] > a[i]) {
        tot++;
      }
    }
  }
  tot %= 2;
  cin>>m;
  while(m-->0) {
    int l, r;
    scanf("%d%d", &l, &r);
    int det = r-l+1;
    det /= 2;
    if (det % 2) tot ^= 1;
    if (tot) puts("odd");
    else puts("even");
  }
  return 0;
}
