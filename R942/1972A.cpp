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
#define N 200005
#define M 5005
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
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    int ans=0;
    int cur=1;
    for (int i = 1; i <= n; ++i) {
      while(cur <= n && a[i] > b[cur]) {
        cur++;
        ans++;
      }
      if (cur <= n) {
        cur++;
      }
      if (cur > n) break;
    }
    printf("%d\n", ans);
  }
  return 0;
}
