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
#define M 202
#define N 20000
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  scanf("%d", &n);
  for (int i = 1; i <= 2*n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a+1, a+2*n+1);
  int ans = inf;
  for (int i = 1; i <= 2*n; ++i) {
    for (int j=  1; j <= 2*n; ++j) {
      if (i == j) continue;
      int pre = -1;
      int mx = 0;
      for (int k = 1; k <= 2*n; ++k) {
        if (k == i || k == j) continue;
        if (pre < 0) pre = k;
        else {
          mx += a[k] - a[pre];
          pre = -1;
        }
      }
      ans = min(ans, mx);
    }
  }
  cout<<ans<<endl;
  //}
  return 0;
}
