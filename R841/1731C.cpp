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
#define N 2000005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
int a[N];
int cnt[N];
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    //ll n;
    scanf("%d", &n);
    for (int i = 0; i < 3 * n; ++i) {
      cnt[i] = 0;
    }
    cnt[0]++;
  //  cout<<getres(n)<<" "<<getres(n-1)<<endl;
    int res=0;
    ll tot = 0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      res ^= a[i];
      for (int qr = 0; qr * qr <= 3 * n; ++qr) {
        tot += cnt[res ^ (qr * qr)];
      }
      cnt[res]++;
    }
    tot = (ll)n*(ll)(n+1)/2 - tot;
    printf("%lld\n", tot);
  }
  return 0;
}
