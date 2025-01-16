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
#define N 500005
#define M 405
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N], b[N];
ll getpw(ll x, ll y) {
    ll res=1LL;
    while(y) {
        if (y&1) res=res*x%mod;
        x=x*x%mod;
        y/=2;
    }
    return res;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {

  // }
  cin>>n;
  for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i =1; i <= n; ++i) {
        ll res = getpw(2LL, b[i]) % mod;
        printf("%lld\n", res);
    }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
