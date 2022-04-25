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
#define N 400005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    map<int, int> mp1, mp2;
    mp1.clear();
    mp2.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      mp1[a[i]]++;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    bool ok = true;
    int cur = 1;
    for (int i = 1; i <= n; ++i) {
      if (b[i] == a[cur]) {
        mp1[a[cur]]--;
        cur++;
      } else {
        if (i > 1 && b[i] == b[i-1] && mp2[b[i]]>0) {
          mp2[b[i]]--;
        } else {
          int j = cur;
          while(j <= n && a[j] != b[i]) {
            mp2[a[j]]++;
            mp1[a[j]]--;
            if (mp1[a[j]] == 0) {
              ok=false;
              break;
            }
            j++;
          }
          if (!ok) break;
          if (j > n) {
            ok=false;
            break;
          }
          mp1[a[j]]--;
          cur = j+1;
        }
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
