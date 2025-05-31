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
#define M 1002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
ll k;
int t;
int a[N];
ll calc(ll x, ll y) {
    ll res=0;
    while(x>1) {
        res++;
        if (x&1) x = (x+1)/2;
        else x=x/2;
    }
    while(y > 1) {
        res++;
        if (y&1) y = (y+1)/2;
        else y=y/2;
    }
    return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll n,m,x,y;
    scanf("%lld%lld%lld%lld", &n, &m, &x, &y);
    ll ans = min(min(calc(x, m), calc(n-x+1, m)), min(calc(n, y), calc(n, m-y+1))) + 1;
    printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
