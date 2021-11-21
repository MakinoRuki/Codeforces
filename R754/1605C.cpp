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
#define M 52
#define N 702
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
ll k;
int q, p;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    bool found=false;
    for (int i = 1; i < n; ++i) {
      if (s[i] == 'a' && s[i-1] == 'a') {
        found=true;
        break;
      }
    }
    if (found) {
      puts("2");
    } else {
      for (int i = 0; i + 2 < n; ++i) {
        if (s[i] == 'a' && s[i+2] == 'a') {
          found=true;
          break;
        }
      }
      if (found) puts("3");
      else {
        for (int i = 0; i + 3 < n; ++i) {
          if (s.substr(i, 4) == "abca" || s.substr(i, 4) == "acba") {
            found=true;
            break;
          }
        }
        if (found) puts("4");
        else {
          for (int i = 0; i + 6 < n; ++i) {
            if (s.substr(i, 7) == "abbacca" || s.substr(i, 7) == "accabba") {
              found=true;
              break;
            }
          }
          if (found) puts("7");
          else puts("-1");
        }
      }
    }
  }
  return 0;
}
