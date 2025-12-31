
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
#define M 105
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    ll ans = (ll)n*(ll)(n+1);
    int cur=0,cnt=0;
    for (int i = 1; i <= n; ++i) {
      if (i == 1 || a[i] == a[i-1]) {
        cur = a[i];
        cnt++;
      } else {
        ans = min(ans, (ll)(n-cnt) * (ll)cur);
        cur = a[i];
        cnt=1;
      }
    }
    if (cnt) {
      ans = min(ans, (ll)(n-cnt)*(ll)cur);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
