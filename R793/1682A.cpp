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
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int cnt[26][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j <= n; ++j) {
        cnt[i][j] = 0;
      }
    }
    for (int i = 0; i < 26; ++i) {
      for (int j = 1; j <= n; ++j) {
        cnt[i][j] = cnt[i][j-1];
        if (s[j-1] == 'a' + i) {
          cnt[i][j]++;
        }
      }
    }
    int ans=0;
    for (int i = 1; i <= n; ++i) {
      int j = n+1-i;
      bool ok = false;
      if (i <= j) {
        int c;
        for (c = 0; c < 26; ++c) {
          if (cnt[c][j] - cnt[c][i] == j-i) {
            ok=true;
            break;
          }
        }
      } else {
        int c;
        for (c = 0; c < 26; ++c) {
          if (cnt[c][i-1] - cnt[c][j-1] == i-j) {
            ok=true;
            break;
          }
        }
      }
      if (ok) ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
