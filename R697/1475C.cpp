#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int a,b,k;
int an[N], bn[N];
int cnta[N], cntb[N];
map<pair<int,int>, int> cnt;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &a, &b, &k);
    for (int i = 1; i <= a; ++i) {
      cnta[i] = 0;
    }
    for (int i = 1; i <= b; ++i) {
      cntb[i] = 0;
    }
    cnt.clear();
    for (int i = 1; i <= k; ++i) {
      scanf("%d", &an[i]);
      cnta[an[i]]++;
    }
    for (int i = 1; i <= k; ++i) {
      scanf("%d", &bn[i]);
      cntb[bn[i]]++;
    }
    for (int i = 1; i <= k; ++i) {
      cnt[make_pair(an[i], bn[i])]++;
    }
    ll tot=0LL;
    for (int i = 1; i <= k; ++i) {
      ll cur = cnta[an[i]]+cntb[bn[i]];
      if (cnt.find(make_pair(an[i], bn[i])) != cnt.end()) {
        cur -= cnt[make_pair(an[i], bn[i])];
      }
      tot += k-cur;
    }
    printf("%lld\n", tot/2);
  }
  return 0;
}
