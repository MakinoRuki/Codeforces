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
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int q;
int lmx[N], rmx[N];
int umx[N], dmx[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    string s;
    cin>>s;
    int dx= 0, dy = 0;
    int x = 1, y = 1;
    for (int i = 0; i < s.size(); ++i) {
      lmx[i] = 0;
      rmx[i] = 0;
      umx[i] = 0;
      dmx[i] = 0;
    }
    for (int i = 0; i < s.size(); ++i) {
      if (i > 0) {
        lmx[i] = lmx[i-1];
        rmx[i] = rmx[i-1];
        umx[i] = umx[i-1];
        dmx[i] = dmx[i-1];
      }
      if (s[i] == 'L' || s[i] == 'R') {
        if (s[i] == 'L') dx--;
        else dx++;
        if (dx > 0) {
          rmx[i] = max(rmx[i], dx);
        } else {
          lmx[i] = max(lmx[i], -dx);
        }
      } else {
        if (s[i] == 'U') dy++;
        else dy--;
        if (dy > 0) {
          umx[i] = max(umx[i], dy);
        } else {
          dmx[i] = max(dmx[i], -dy);
        }
      }
      if (lmx[i] + rmx[i] + 1 <= m && umx[i] + dmx[i] + 1 <= n) {
        x = umx[i]+1;
        y = lmx[i]+1;
      } else {
        break;
      }
    }
    printf("%d %d\n", x, y);
  }  
  return 0;
}
