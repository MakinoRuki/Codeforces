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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, a, b;
int c[N];
int main() {
  cin>>n>>a>>b;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &c[i]);
  }
  int l = 1, r = n;
  int ans=0;
  while(l < r) {
    if (c[l] != 2 && c[r] != 2) {
      if (c[l] != c[r]) {
        ans = -1;
        break;
      }
    } else if (c[l] != 2) {
      if (c[l]==0) ans += a;
      else ans += b;
    } else if (c[r] != 2) {
      if (c[r]==0) ans += a;
      else ans += b;
    } else {
      ans += min(a,b)*2;
    }
    l++;
    r--;
  }
  if (l==r) {
    if (c[l] == 2) {
      ans += min(a,b);
    }
  }
  cout<<ans<<endl;
  return 0;
}
