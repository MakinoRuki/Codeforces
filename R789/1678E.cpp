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
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int a[N];
int b[N];
int c[N];
bool vis[N];
int main() {
  cin>>t;
//  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      vis[i] = false;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      c[a[i]] = b[i];
    }
    int tot=0;
    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) {
        int cur=i;
        int len=0;
        while(!vis[cur]) {
          vis[cur]=true;
          len++;
          cur=c[cur];
        }
        tot += len/2;
      }
    }
    int l = 1, r = n;
    ll res=0LL;
    for (int i = 1; i <= tot; ++i) {
      if (l < r) {
        res += 2LL*(r-l);
        l++;
        r--;
      } else {
        break;
      }
    }
    printf("%lld\n", res);
  }
  return 0;
}
