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
#define N 300000
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
int xs[N];
int f[N][2];
ll sum[N];
int main() {
  cin>>n>>q;
  xs[0]=0;
  map<int, int> mp0;
  map<int, int> mp1;
  mp0[0] = 0;
  sum[0]=0;
  for (int i = 1; i <= n; ++i) {
    f[i][0]=-1;
    f[i][1]=-1;
    scanf("%d", &a[i]);
    sum[i] = sum[i-1]+a[i];
    xs[i]=xs[i-1]^a[i];
    if (mp0.find(xs[i]) != mp0.end()) {
      f[i][0] = mp0[xs[i]];
    }
    if (mp1.find(xs[i]) != mp1.end()) {
      f[i][1] = mp1[xs[i]];
    }
    if (i%2) mp1[xs[i]] = i;
    else mp0[xs[i]] = i;
  }
  while(q-->0) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (sum[r]-sum[l-1] == 0) {
      puts("0");
      continue;
    }
    if (xs[r] != xs[l-1]) {
      puts("-1");
      continue;
    }
    if ((r-l+1)%2) {
      puts("1");
    } else {
      int id = -1;
      if (r%2) {
        id = f[r][0];
      } else {
        id = f[r][1];
      }
      if (id < 0 || id < l) {
        puts("-1");
      } else {
        if (id == r-1 || xs[l]==xs[l-1]) {
          puts("1");
        } else {
          puts("2");
        }
      }
    }
  }
  return 0;
}
