
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
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
ll a[N];
int p[N];
ll getgcd(ll x, ll y) {
  return y == 0 ? x : getgcd(y, x%y);
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
    ll k;
    scanf("%d%lld", &n, &k);
    int c1=0,c2=0,c0=0;
    vector<ll> v;
    v.clear();
    for (int i =1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      ll tmp = a[i]-k;
      if (tmp > 0) c1++;
      else if (tmp < 0) c2++;
      else c0++;
      v.push_back(tmp);
    }
    if (c1 && c2) {
      puts("-1");
      continue;
    }
    if (c1 && c0) {
      puts("-1");
      continue;
    }
    if (c2 && c0) {
      puts("-1");
      continue;
    }
    if (c1 + c2 == 0) {
      puts("0");
      continue;
    }
    ll g = 0;
    for (auto x : v) {
      g = getgcd(g, abs(x));
    }
    ll ans=0LL;
    if (c2 > 0) {
      for (auto x : v) {
        ans += x/(-g)-1;
      }
    } else {
      for (auto x : v) {
        ans += x/g - 1;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
