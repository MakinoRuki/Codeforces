
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
#define N 200005
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
vector<string> v;
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
    int x, y;
    scanf("%d", &n);
    int ans=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    ll g= 0;
    for (int i = 1; i <= n; ++i) {
      if (i == 1) {
        g = getgcd(b[i], b[i+1]);
        if (g < a[i]) ans++;
      } else if (i == n) {
        g = getgcd(b[i-1], b[i]);
        if (g < a[i]) ans++;
      } else {
        g = getgcd(b[i-1], b[i]);
        ll g2 = getgcd(b[i], b[i+1]);
        ll res = g/getgcd(g, g2) * g2;
        if (res < a[i]) ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}

