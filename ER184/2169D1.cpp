
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
#define M 8002
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
int a[N];
ll sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll x,y,k;
    scanf("%lld%lld%lld", &x, &y, &k);
    ll cur = k;
    for (int i = 1; i <= x; ++i) {
      ll l = 1, r = 1000000000001LL;
      while(l < r) {
        ll mid=(l+r)/2;
        if (mid-mid/y >= cur) {
          r = mid;
        } else {
          l = mid+1;
        }
      }
      cur = r;
    }
    if (cur > 1000000000000LL || cur < 1) {
      puts("-1");
    } else {
    printf("%lld\n", cur);
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
