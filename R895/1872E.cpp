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
#define N 200000
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
ll sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    sum[0] = 0LL;
    ll ans = 0LL;
    ll tot = 0LL;
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
      sum[i] = sum[i-1] ^ a[i];
      tot ^= a[i];
    }
    string s;
    cin>>s;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') ans ^= a[i+1];
    }
    scanf("%d", &q);
    while(q-->0) {
      int tp;
      scanf("%d", &tp);
      if (tp == 1) {
        int l, r;
        scanf("%d%d", &l, &r);
        ans ^= sum[r] ^ sum[l-1];
      } else {
        int g;
        scanf("%d", &g);
        if (g) printf("%lld ", ans);
        else printf("%lld ", tot ^ ans);
      }
    }
    cout<<endl;
  }
  return 0;
}
