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
#define N 500005
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int ans[N];
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    set<pair<int,int>> sa;
    set<pair<int,int>> sb;
    sa.clear();
    sb.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      sa.insert(make_pair(a[i], i));
    }
    for (int i =1; i <= m; ++i) {
      scanf("%d", &b[i]);
      sb.insert(make_pair(b[i], i+n));
    }
    int up = 1000;
    if (k%2) up++;
    for (int i = 1; i <= up; ++i) {
      if (i%2) {
        if ((*sa.begin()).first <= (*sb.rbegin()).first) {
          auto pa = *sa.begin();
          auto pb = *sb.rbegin();
          sa.erase(pa);
          sa.insert(pb);
          sb.erase(pb);
          sb.insert(pa);
        }
      } else {
        if ((*sb.begin()).first <= (*sa.rbegin()).first) {
          auto pb = *sb.begin();
          auto pa = *sa.rbegin();
          sa.erase(pa);
          sa.insert(pb);
          sb.erase(pb);
          sb.insert(pa);
        }
      }
    }
    ll ans=0LL;
    for (auto itr : sa) {
      ans += itr.first;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
