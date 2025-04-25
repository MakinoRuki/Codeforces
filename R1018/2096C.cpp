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
#define N 600005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int b[N];
int h[M][M];
ll dpr[M][2];
ll dpc[M][2];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &h[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int s = 0; s < 2; ++s) {
            dpr[i][s] = (1LL<<61)-1;
            dpc[i][s] = (1LL<<61)-1;
        }
    }
    dpr[1][1] = a[1];
    dpr[1][0] = 0;
    for (int i = 1; i < n; ++i) {
        for (int s1 = 0; s1 < 2; ++s1) {
            for (int s2 = 0; s2 < 2; ++s2) {
                bool ok = true;
                for (int j = 1; j <= n; ++j) {
                    if (h[i][j] + s1 == h[i+1][j] + s2) {
                        ok=false;
                        break;
                    }
                }
                if (ok) {
                    dpr[i+1][s2] = min(dpr[i+1][s2], dpr[i][s1] + s2 * a[i+1]);
                }
            }
        }
    }
    dpc[1][1] = b[1];
    dpc[1][0] = 0;
    for (int i = 1; i < n; ++i) {
        for (int s1 = 0; s1 < 2; ++s1) {
            for (int s2 = 0; s2 < 2; ++s2) {
                bool ok = true;
                for (int j = 1; j <= n; ++j) {
                    if (h[j][i] + s1 == h[j][i+1] + s2) {
                        ok=false;
                        break;
                    }
                }
                if (ok) {
                    dpc[i+1][s2] = min(dpc[i+1][s2], dpc[i][s1] + s2 * b[i+1]);
                }
            }
        }
    }
    ll rans = min(dpr[n][0], dpr[n][1]);
    ll cans = min(dpc[n][0], dpc[n][1]);
    ll ans = -1;
    if (rans < (1LL<<61)-1 && cans < (1LL<<61)-1) {
        ans = rans + cans;
    }
    printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
