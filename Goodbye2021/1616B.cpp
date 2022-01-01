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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, q, k;
char ss[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    scanf("%s", ss);
    string s(ss);
    string ans;
    if (n == 1) {
      ans = s + s;
    } else {
      if (s[0] == s[1]) {
        ans = s.substr(0, 2);
      } else {
        int i;
        for (i = 1; i < n; ++i) {
          if (s[i] > s[i-1]) {
            break;
          }
        }
        if (i < n) {
          s = s.substr(0, i);
          string t = s;
          reverse(t.begin(), t.end());
          ans = s + t;
        } else {
          string t = s;
          reverse(t.begin(), t.end());
          ans = s + t;
        }
      }
    }
    printf("%s\n", ans.c_str());
  }
  return 0;
}
