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
#define N 200005
#define M 3000000
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q, p;
int t;
int d;
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
    
  // }
  cin>>n>>t>>k>>d;
  int ans = (n+k-1)/k*t;
  int tot=0;
  bool ok=false;
 // cout<<ans<<endl;
  for (int i = 1; i <= 2000000; ++i) {
    if (i % t == 0) {
      tot += k;
    }
    if (i > d && (i-d)%t==0) {
      tot += k;
    }
    if (tot >= n) {
     // cout<<"i="<<i<<endl;
      if (i < ans) {
        ok=true;
      }
      break;
    }
  }
  if (ok) puts("YES");
  else puts("NO");
  return 0;
}
