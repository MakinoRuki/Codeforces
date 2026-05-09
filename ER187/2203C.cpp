
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
bool check(ll s, ll n, ll m) {
  ll cur=0LL;
  for (int i = 60; i >= 0; --i) {
    cur *= 2;
    if ((1LL<<i)&s) cur++;
    if ((1LL<<i)&m) {
      cur -= min(cur, n);
    }
  }
  if (cur<=0) return true;
  return false;
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
    int d;
    ll x;
    ll s,m;
    scanf("%lld%lld", &s, &m);
    ll l = 1, r = 1e18;
    while(l<r) {
      ll mid=(l+r)/2;
      if (check(s, mid, m)) {
        r = mid;
      }else {
        l=mid+1;
      }
    }
    if (check(s, r, m)) {
      printf("%lld\n", r);
    } else {
      puts("-1");
    }
  }
  return 0;
}

