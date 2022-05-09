#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <list>
#include <random>
#define N 100005
#define M 502
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
bool c[27];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    char ss[N];
    scanf("%s", ss);
    string s = string(ss);
    int pre = 0;
    memset(c, false, sizeof(c));
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
      char xx[3];
      scanf("%s", xx);
      c[xx[0]-'a'] = true;
    }
    int ans=0;
    for (int i = 0; i < n; ++i) {
      if (c[s[i]-'a']) {
        ans = max(ans, i - pre);
        pre = i;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
