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
#define N 5002
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
ll a[N];
ll comb[N][N];
string s;
int main() {
  memset(comb, 0LL, sizeof(comb));
  for (int i = 0; i < N; ++i) {
    comb[i][0] = 1LL;
    for (int j = 1; j <= i; ++j) {
      comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % mod2;
    }
  }
  cin>>n>>k;
  cin>>s;
  ll ans = 0LL;
  int tot=0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      tot++;
      int id1 = i-1;
      while(id1 >= 0 && s[id1] == '0') {
        id1--;
      }
      id1++;
      int id2 = i;
      int cnt=0;
      while(id2 < n) {
        if (s[id2] == '1') {
          cnt++;
        }
        if (cnt > k) break;
        id2++;
      }
      id2--;
      if (cnt > k) cnt--;
      if (id1 < id2) {
        for (int j = id1; j <= id2; ++j) {
          if (j == i) continue;
          if (id2 - j < cnt-1) {
            break;
          }
          ans = (ans + comb[id2-j][cnt-1]) % mod2;
        }
      }
    }
  }
  ans = (ans + 1LL) % mod2;
  if (tot < k) {
    ans = 1LL;
  }
  cout<<ans<<endl;
  return 0;
}
