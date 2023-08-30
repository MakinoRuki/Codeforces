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
#define N 200005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll n;
    scanf("%lld", &n);
    ll l = 0, r = 2000000000LL;
    while(l < r) {
      ll mid = (l+r+1)/2;
      if (mid*(mid-1)/2 > n) {
        r = mid-1;
      } else {
        l = mid;
      }
    }
    ll dt = n-r*(r-1)/2;
    printf("%lld\n", r+dt);
  }
  return 0;
}
