
#include <iostream>
#include <sstream>
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
#define N 500005
#define M 110
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int b[N];
int p;
ll sum[3][N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // ll ans=1LL;
  // for (int i =1; i <= 500; ++i) {
  //   ans=ans*5813LL%9422LL;
  // }
  // cout<<ans<<endl;
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x, y;
    ll ct,ch,cu;
    scanf("%d%d%d%d", &n, &k, &p, &q);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    sum[0][0]=sum[1][0]=sum[2][0]=0LL;
    for (int i = 1; i <= n; ++i) {
      ll r1 = a[i]%p;
      ll r2 = a[i]%q%p;
      sum[0][i] = sum[0][i-1]+min(r1,r2);
      sum[1][i] = sum[1][i-1]+r1;
      sum[2][i] = sum[2][i-1]+r2;
    }
    ll ans = min(sum[1][n], sum[2][n]);
    for (int i = k; i <= n; ++i) {
      ans = min(ans, sum[0][i-k]+sum[0][n]-sum[0][i]+min(sum[1][i]-sum[1][i-k], sum[2][i]-sum[2][i-k]));
    }
    printf("%lld\n", ans);
  }
  return 0;
}

