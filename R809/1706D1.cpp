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
#define N 3005
#define M 300005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
set<int> ns[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      ns[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      for (int j = 1; j <= k; ++j) {
        ns[i].insert(a[i]/j);
      }
    }
  //  cout<<"ok"<<endl;
    int ans=inf;
    for (int i = 1; i <= 3000; ++i) {
      bool found=false;
      int mx = i;
      int j;
    //  if (i == 4) cout<<"n="<<n<<endl;
      for (j = 1; j <= n; ++j) {
     //   if (i == 4) cout<<"jjj="<<j<<endl;
        auto itr = ns[j].lower_bound(i);
        if (itr == ns[j].end()) {
      //    if (i == 4) cout<<"jj="<<j<<endl;
          break;
        }
      //  if (i == 4) cout<<"j="<<j<<" "<<(*itr)<<endl;
        if ((*itr) == i) {
          found=true;
        } else {
          mx = max(mx, (*itr));
        }
      }
      if (j <= n) {
        break;
      }
      if (found) ans = min(ans, mx-i);
    }
    printf("%d\n", ans);
  }
  // int ans=0;
  // for (int i = 1; i <= 3000; ++i) {
  //   int cnt=0;
  //   for (int j = 1; j * j <= i; ++j) {
  //     if ((i % j) == 0) {
  //       cnt++;
  //       if (i/j != j) cnt++;
  //     }
  //   }
  //   ans += cnt;
  //   //ans=max(ans, cnt);
  // }
  // cout<<ans<<endl;
  return 0;
}
