
#include <iostream>
#include <sstream>
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
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int p[N];
int idx[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<int> ids;
    ids.clear();
    int qr = (int)sqrt(n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] >= qr) {
        ids.push_back(i);
      }
    }
    ll ans=0LL;
    for (int i = 1; i <= n; ++i) {
      for (ll aj = 1; aj <= qr; ++aj) {
        ll j = (ll)a[i]*aj+i;
        if (j >= 1 && j <= n && j > i && a[j] == aj) {
          ans++;
        }
      }
    }
    for (int j = 1; j <= n; ++j) {
      for (ll ai = 1; ai <= qr; ++ai) {
        if (a[j] <= qr && ai <= qr) continue;
        ll i = j - (ll)a[j] * ai;
        if (i >= 1 && i <= n && j > i && a[i] == ai) ans++;
      }
    }
    // for (auto i : ids) {
    //   for (int aj = 1; a[i]*aj <= n; ++aj) {
    //     int j = a[i]*aj+i;
    //     if (j > i && a[j] == aj) {
    //       ans++;
    //     }
    //   }
    // }
    // for (auto j : ids) {
    //   for (int ai = 1; ai *a[j] <= n; ++ai) {
    //     int i = j-a[j]*ai;
    //     if (i < j && a[i] == ai) {
    //       ans++;
    //     }
    //   }
    // }
    printf("%lld\n", ans);
  }
  return 0;
}

