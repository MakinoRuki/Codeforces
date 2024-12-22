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
#define N 200005
#define M 1005
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
int a[N];
ll cal1(ll x) {
    if (x <= 0) return x;
    if (x%2) {
        x/=2;
        if (x%2) return 0;
        return 1;
    } else {
        ll y = x;
        y--;
        y/=2;
        if (y%2) return x;
        return x^1;
    }
}
ll cal2(ll r, ll x, ll k) {
    if (r == 0) {
        if ((r % (1LL<<x))==k) return r;
        return 0;
    }
    ll v = r;
    vector<int> bs;
    bs.clear();
    while(v) {
        bs.push_back(v%2);
        v/=2;
    }
    reverse(bs.begin(), bs.end());
    int sz= (int)bs.size();
    if (sz <= x) {
        if (k <= r) return k;
        return 0;
    }
    ll res = 0LL;
    for (int i = 0; i < sz-x; ++i) {
        if (bs[i] == 1) {
            int len = sz-x-i-1;
            if (len>0) {
                ll tmp = cal1((1LL<<len)-1);
                tmp <<= x;
                res ^= tmp;
            } else if (len == 0) {
                ll tmp = r ^ (1LL<<x);
                tmp -= tmp%(1LL<<x);
                tmp += k; 
                res ^= tmp;
            }
        }
    }
    ll tmp = r - (r % (1LL<<x));
    tmp += k;
    if (tmp <= r) res ^= tmp;
    return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll l, r;
    int x,k;
    scanf("%lld%lld%d%d", &l, &r, &x, &k);
    ll ans = cal1(l-1) ^ cal1(r);
  //  cout<<"ans="<<ans<<endl;
    ll tmp = cal2(l-1, x, k) ^ cal2(r, x, k);
   // cout<<"tmp="<<tmp<<endl;
    ans ^= tmp;
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

