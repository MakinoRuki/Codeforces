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
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    map<int, ll> mp;
    mp.clear();
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
        mp[abs(b[i])]+=a[i];
    }
    bool ok=true;
    ll tot=0LL;
    for (auto itr : mp) {
        int d = itr.first;
        tot +=itr.second;
        if ((ll)d * (ll)k < tot) {
            ok=false;
            break;
        }
    }
    if (ok) puts("Yes");
    else puts("No");
  }
  return 0;
}
