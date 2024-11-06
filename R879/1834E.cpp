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
#define N 500005
#define M 325
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
ll a[N];
const ll up = 4256233;
ll getgcd(ll x, ll y) {
  return y == 0 ? x : getgcd(y, x%y);
}
ll getlcm(ll x, ll y) {
  ll gcd = getgcd(x, y);
  ll res = x/gcd * y;
  return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    set<ll> ss;
    ss.clear();
    set<ll> res;
    res.clear();
    for (int i = 1; i <= n; ++i) {
      set<ll> tmp;
      tmp.clear();
      for (auto itr : ss) {
        ll lcm = getlcm(itr, a[i]);
        if (lcm > up) continue;
        tmp.insert(lcm);
      }
      ss.clear();
      for (auto itr : tmp) {
        ss.insert(itr);
        res.insert(itr);
      }
      ss.insert(a[i]);
      res.insert(a[i]);
    }
    ll ans = 1LL;
    for (auto itr : res) {
      if (itr == ans) ans++;
      else break;
    }
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

