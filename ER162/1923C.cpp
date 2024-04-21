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
ll sum[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    cnt[0]=0;
    sum[0]=0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum[i] = sum[i-1] + (ll)a[i];
        cnt[i] = cnt[i-1] + (a[i]==1);
    }
    while(q-->0) {
        int l, r;
        scanf("%d%d", &l, &r);
        int n1 = cnt[r] - cnt[l-1];
        if (r-l+1 <= 1) {
            puts("No");
            continue;
        }
        if (n1 <= 0) {
            puts("Yes");
        } else {
            ll tot = sum[r]-sum[l-1];
            if (tot - n1 >= r-l+1) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
    }
  }
  return 0;
}
