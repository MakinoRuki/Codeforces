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
#define N 300005
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    vector<int> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      v.push_back(a[i]);
    }
    if (k > 1) {
      puts("YES");
    } else {
      sort(v.begin(), v.end());
      bool ok=true;
      for (int i= 1; i <= n; ++i) {
        if (a[i] != v[i-1]) {
          ok=false;
          break;
        }
      }
      if (ok) puts("YES");
      else puts("NO");
    }
  }
  return 0;
}
