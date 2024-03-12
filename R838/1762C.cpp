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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
ll pw[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    pw[0] = 1LL;
    for (int i = 1; i <= n; ++i) {
        pw[i] = pw[i-1] * 2LL % mod2;
    }
    ll ans=0LL;
    int cnt=0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || s[i] == s[i-1]) {
            cnt++;
        } else {
            cnt = 1;
        }
        ans = (ans + pw[cnt-1]) % mod2;
    }
    printf("%lld\n", ans);
  }
  return 0;
}

