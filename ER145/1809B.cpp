#include <iostream>
#include <cstdio>
#include <stdio.h>
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
#include <cstring>
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
int num;
int mp[N];
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    ll n;
    scanf("%lld", &n);
    ll l = 1LL, r= 1000000000LL;
    while(l < r) {
      ll mid = (l+r)/2;
      if (mid * mid >= n) {
        r = mid;
      } else {
        l = mid+1;
      }
    }
    printf("%lld\n", r-1);
  }
  return 0;
}
