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
int k;
int t;
ll a[N];
ll lmx[N], rmx[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll k;
    scanf("%d%lld", &n, &k);
    string s;
    cin>>s;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    lmx[0]=0;
    for (int i = 1; i <= n; ++i) {
      if (i==1) lmx[i]=a[i];
      else {
        lmx[i] = max(lmx[i-1]+a[i], a[i]);
      }
    }
    rmx[n+1]=0;
    for (int i = n; i >= 1; --i) {
      if (i==n) rmx[i]=a[i];
      else {
        rmx[i] = max(rmx[i+1]+a[i], a[i]);
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (s[i-1] == '0') {
        ll lv = max(lmx[i-1], 0LL);
        ll rv = max(rmx[i+1], 0LL);
        a[i] = k-lv-rv;
      }
      lmx[i] = max(lmx[i-1]+a[i], a[i]);
    }
    ll ans=0LL;
    for (int i = 1; i <= n; ++i) {
      ans=max(ans, lmx[i]);
    }
    if (ans == k) {
      puts("Yes");
      for (int i = 1; i <= n; ++i) {
        printf("%lld ", a[i]);
      }
      cout<<endl;
    } else {
      puts("No");
    }
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
