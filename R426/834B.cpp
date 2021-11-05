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
int t, n, h;
int k;
int q;
int st[26], ed[26];
int main() {
  cin>>n>>k;
  string s;
  cin>>s;
  memset(st, -1, sizeof(st));
  memset(ed, -1, sizeof(ed));
  for (int i = 0; i < n; ++i) {
    int c = s[i]-'A';
    if (st[c] < 0) {
      st[c] = i;
      ed[c] = i;
    } else {
      ed[c] = i;
    }
  }
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    int cnt=0;
    for (int j = 0; j < 26; ++j) {
      if (st[j] <= i && ed[j] >= i) {
        cnt++;
      }
    }
    if (cnt > k) {
      ok=false;
      break;
    }
  }
  if (!ok) puts("YES");
  else puts("NO");
  return 0;
}
