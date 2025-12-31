
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
ll a[N];
ll b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll k;
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &b[i]);
    }
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    int ans=0;
    int cur = n;
    for (int i =1 ; i <= n; ++i) {
      while(cur >= 1 && a[cur]*(b[i]+1) + b[i] > k) {
        cur--;
      }
      if (cur >= 1) {
        ans++;
        cur--;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
