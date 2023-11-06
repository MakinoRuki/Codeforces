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
#define N 300005
#define M 20
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    vector<int> v;
    v.clear();
    for (int i =1 ; i <= n; ++i) {
      scanf("%d", &k);
      v.push_back(k);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= m; ++i) {
      ll a,b,c;
      scanf("%lld%lld%lld", &a, &b, &c);
      int id = upper_bound(v.begin(), v.end(), b) - v.begin();
      int kk = -inf;
      if (id == 0) {
        kk = v[id];
      } else if (id >= v.size()) {
        kk = v[id-1];
      } else {
        kk = v[id];
        if (id-1>=0 && abs(v[id-1]-b) <= abs(kk-b)) {
          kk = v[id-1];
        }
      }
      if (kk > -inf && (b-kk)*(b-kk) < 4LL * a * c) {
        puts("YES");
        printf("%d\n", kk);
      } else {
        puts("NO");
      }
    }
  }
  return 0;
}
