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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    bool ok = true;
    if (s.back() != 'B') {
      ok=false;
    } else {
      int sum = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A') {
          sum++;
        } else {
          sum--;
        }
        if (sum < 0) {
          ok=false;
          break;
        }
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
