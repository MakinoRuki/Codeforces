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
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    int i= 0;
    n = (int)s.size();
    int cnt=0;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (i == 0 || s[i] == s[i-1]) {
        cnt++;
      } else {
        int j;
        for (j = 0; j <= cnt; ++j) {
          int det = cnt - 2 * j;
          if (det >= 0 && (det % 3 == 0)) {
            break;
          }
        }
        if (j <= cnt) {
          cnt = 1;
          continue;
        }
        ok=false;
        break;
      }
    }
    if (cnt > 0) {
      int j;
      for (j = 0; j <= cnt; ++j) {
        int det = cnt - 2 * j;
        if (det >= 0 && (det % 3 == 0)) {
          break;
        }
      }
      if (j > cnt) {
        ok=false;
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
