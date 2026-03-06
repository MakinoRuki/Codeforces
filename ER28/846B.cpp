/* 枚举完整做几道题 */

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
#define N 1000005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int b[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d%d", &n, &m);

  // }
  cin>>n>>k>>m;
  int tot=0;
  for (int i = 1; i <= k; ++i) {
    scanf("%d", &a[i]);
    tot += a[i];
  }
  sort(a+1, a+k+1);
  int ans=0;
  for (int i = 0; i <= n; ++i) {
    int dt = n-i;
    int sum = m-(ll)tot*(ll)i;
    if (sum < 0) break;
    int res=i*(k+1);
    for (int j = 1; j < k; ++j) {
      res += min(dt, sum/a[j]);
      if (sum / a[j] < dt) {
        break;
      }
      sum -= a[j] * min(dt, sum/a[j]);
    }
   // cout<<"i="<<i<<" "<<res<<endl;
    ans = max(ans, res);
  }
  cout<<ans<<endl;
  return 0;
}
