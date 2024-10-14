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
#define N 500005
#define M 505
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
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    map<ll, ll> mp;
    mp.clear();
    for (int i = 1; i <= n; ++i) {
      ll l = i, r = n-i+1;
      mp[l*r-1]++;
      if (i < n) {
        r = n-i;
        mp[l*r] += a[i+1]-a[i]-1;
      }
    }
    for (int i = 1; i <= q; ++i) {
      ll k;
      scanf("%lld", &k);
      if (mp.find(k) != mp.end()) {
        printf("%lld ", mp[k]);
      } else {
        printf("0 ");
      }
    }
    cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

