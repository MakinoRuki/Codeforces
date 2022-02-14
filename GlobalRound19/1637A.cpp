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
#define M 202
#define N 20000
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      b[i] = a[i];
    }
    sort(b+1, b+n+1);
    set<int> ss;
    ss.clear();
    bool ok = false;
    for (int i = 1; i < n; ++i) {
      ss.insert(a[i]);
      if ((*ss.rbegin()) > b[i]) {
        ok=true;
        break;
      }
    }
    ss.clear();
    for (int i = n; i > 1; --i) {
      ss.insert(a[i]);
      if ((*ss.begin()) < b[i]) {
        ok=true;
        break;
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
