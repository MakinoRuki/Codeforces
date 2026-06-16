
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
#define N 2000005
#define M 5002
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
ll ceil_div(ll a, ll b) {
    return (a + b - 1) / b;
}
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
 //  ll x, y;
  // ll n;
   ll n, x, y, z;
  scanf("%lld%lld%lld%lld", &n, &x, &y, &z);

  ll t1 = ceil_div(n, x + y);

  ll tm = x * z;

  ll t2;
  if (tm >= n) {
      t2 = ceil_div(n, x);
  } else {
      ll remain = n - tm;
      t2 = z + ceil_div(remain, x + 10 * y);
  }

  cout << min(t1, t2) << '\n';
 }
 return 0;
}


