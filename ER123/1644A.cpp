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
#define M 202
#define N 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>s;
    bool r=false, g=false, b=false;
    int i;
    for (i = 0; i< 6; ++i) {
      if (s[i] == 'r') {
        r=true;
      } else if (s[i] == 'g') {
        g=true;
      } else if (s[i] == 'b') {
        b=true;
      } else if (s[i] == 'R') {
        if (!r) break;
      } else if (s[i] == 'G') {
        if (!g) break;
      } else {
        if (!b) break;
      }
    }
    if (i >= 6) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
