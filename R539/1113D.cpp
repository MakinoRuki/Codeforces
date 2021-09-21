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
#define N 5002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, v, k;
string s;
bool dp[N][N];
bool check() {
  for (int i = 0; i < n-1; ++i) {
    string t = s.substr(i+1) +  s.substr(0, i+1);
    if (t == s) continue;
    int l = 0, r= n-1;
    while(l < r) {
      if (t[l] == t[r]) {
        l++;
        r--;
      } else {
        break;
      }
    }
    if (l >= r) return true;
  }
  return false;
}
int main() {
  memset(dp, false, sizeof(dp));
  cin>>s;
  n = (int)s.size();
  set<int> ss;
  ss.clear();
  for (int i = 0; i < n; ++i) {
    ss.insert(s[i] - 'a');
  }
  if (ss.size() == 1) {
    puts("Impossible");
  } else {
    if (n % 2) {
      if (n == 1) puts("Impossible");
      else {
        ss.clear();
        for (int i = (n+1)/2; i < n; ++i) {
          ss.insert(s[i] - 'a');
        }
        if (ss.size() == 1) {
          puts("Impossible");
        } else {
          if (check()) {
            puts("1");
          } else {
            puts("2");
          }
        }
      }
    } else {
      if (check()) puts("1");
      else puts("2");
    }
  }
  return 0;
}
