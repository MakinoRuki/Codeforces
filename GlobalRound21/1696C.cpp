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
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) {
      scanf("%d", &b[i]);
    }
    vector<pair<ll,int>> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      int cnt = 1;
      int x = a[i];
      while(x % m == 0) {
        cnt *= m;
        x/=m;
      }
      if (v.empty() || v.back().second != x) {
        v.push_back(make_pair((ll)cnt, x));
      } else {
        v.back().first += (ll)cnt;
      }
    }
    int j = 0;
    bool ok = true;
    for (int i = 1; i <= k; ++i) {
      if (j >= v.size()) {
        ok=false;
        break;
      }
      int x = v[j].second;
      if (b[i] % x != 0) {
        ok=false;
        break;
      }
      int y = b[i]/x;
      if (y > v[j].first) {
        ok=false;
        break;
      }
      int z = y;
      while(y%m==0) {
        y/=m;
      }
      if (y == 1) {
        v[j].first -= z;
        if (v[j].first == 0) j++;
      } else {
        ok=false;
        break;
      }
    }
    if (ok) {
      if (j < v.size()-1) ok=false;
      else if (j == v.size()-1 && v[j].first != 0) ok=false;
      if (ok) puts("Yes");
      else puts("No");
    } else {
      puts("No");
    }
  }
  return 0;
}
