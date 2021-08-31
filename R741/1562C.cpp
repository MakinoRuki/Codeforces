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
#define N 8000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int t;
string s;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    cin>>s;
    int len = 0;
    int maxl = 0;
    int id0 = -1;
    int st = -1;
    int tst = -1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        if (id0 < 0) id0 = i;
        if (tst < 0) {
          tst = i;
        }
        len++;
        if (len > maxl) {
          maxl = len;
          st = tst;
        }
      } else {
        len = 0;
        tst = -1;
      }
    }
    if (maxl >= n/2) {
      if (maxl == n) {
        printf("%d %d %d %d\n", 1, n/2, n-n/2+1, n);
      } else {
        printf("%d %d %d %d\n", st+1, st+maxl, 1, n);
      }
    } else if (id0 >= 0) {
      id0++;
      if (id0-1 >= n/2) {
        printf("%d %d %d %d\n", 1, id0, 1, id0-1);
      } else {
        printf("%d %d %d %d\n", id0, n, id0+1, n);
      }
    } else {
      printf("%d %d %d %d\n", 1, n/2, n-n/2+1, n);
    }
  }
 return 0;
}
