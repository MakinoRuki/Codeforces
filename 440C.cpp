/* 从高位到低位看，对于当前的数字是z，且在第p位，设x=11...11(p个1)，那么一定是先放z/x个x。
然后剩余部分，可能是再放一个x然后减掉(z/x+1)x-z，也可能是加上z%x。所以要枚举这两种情况去dfs。 */

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
#define N 3000005
#define M 110
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
ll os[N];
ll dfs(ll x, ll c) {
  if (c == 0) return 0;
  ll q = x/os[c];
  ll r = x%os[c];
  if (r == 0) {
    return q*c;
  }
  return q*c + min(dfs(r, c-1), c + dfs(os[c]-r, c-1));
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
  // }
  
  ll n;
  cin>>n;
  os[0]=0;
  for (int i = 1; i <= 16; ++i) {
    os[i]=os[i-1]*10LL+1;
  }
  ll ans = dfs(n, 16);
  cout<<ans<<endl;
  return 0;
}
 
