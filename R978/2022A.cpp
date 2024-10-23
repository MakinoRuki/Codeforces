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
#define N 500005
#define M 1100
#define eps 1e-7
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int r;
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int ans=0;
    int cnt = 0;
    int rn = 0;
    for (int i = 1; i <= n; ++i) {
      ans += a[i]/2*2;
      rn += a[i]/2;
      if (a[i]%2) cnt++;
    }
    rn = r-rn;
    //cout<<ans<<" "<<rn<<" "<<cnt<<endl;
    int dt = cnt - rn;
    ans += min(cnt, rn-dt);
    printf("%d\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

