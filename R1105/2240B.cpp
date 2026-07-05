
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
#define M 1805
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
ll getmod(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod2;
    x=x*x%mod2;
    y /= 2;
  }
  return res;
}
int main() {
 cin>>t;
 for (int cas=1; cas<=t; ++cas) {
 //  ll x, y;
   ll r,c;
   ll n,m;
   scanf("%lld%lld%lld%lld", &n, &m, &r, &c);
 //  string s;
   ll dt = n*m-(n-r+1)*(m-c+1);
   ll res=getmod(2LL, dt);
   printf("%lld\n", res);
 }
 return 0;
}
