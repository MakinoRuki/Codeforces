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
#define M 12
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
string s;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>s;
    int c0=0,c1=0;
    int cnt=0;
    n = (int)s.size();
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        c0++;
      } else if (s[i] == '1') {
        c1++;
      }
      if (i == 0 || s[i] != s[i-1]) {
        if (s[i] == '0') {
          cnt++;
        }
      }
    }
    if (c0 == 0) {
      puts("0");
    } else if (c1 == 0) {
      puts("1");
    } else {
      if (cnt > 1) puts("2");
      else puts("1");
    }
  }
  return 0;
}
