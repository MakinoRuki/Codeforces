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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] == 1) cnt++;
    }
    int l,r;
    for (l=1; l<= n; ++l) {
        if (a[l] == 1) {
            break;
        }
    }
    for (r = n; r >= 1; --r) {
        if (a[r] == 1) {
            break;
        }
    }
    int ans=(r-l+1-cnt);
    printf("%d\n", ans);
  }
  return 0;
}
