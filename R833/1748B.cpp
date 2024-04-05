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
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    ll ans=0LL;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 10; ++j) {
        cnt[j]=0;
      }
      int tot=0;
      int mx=0;
      for (int j = i; j < n; ++j) {
        cnt[s[j]-'0']++;
        mx=max(mx, cnt[s[j]-'0']);
        if (mx > 10) break;
        if (cnt[s[j]-'0'] == 1) {
          tot++;
        }
        if (mx <= tot) {
          ans++;
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
