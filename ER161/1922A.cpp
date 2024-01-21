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
#include <random>
#include <ctime>
#define N 360
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string a,b,c;
    cin>>a>>b>>c;
    bool found=false;
    for (int i = 0; i < n; ++i) {
      if (a[i] == b[i]) {
        if (a[i] != c[i]) {
          found=true;
          break;
        }
      } else {
        if (a[i] != c[i] && c[i] != b[i]) {
          found=true;
          break;
        }
      }
    }
    if (found) puts("YES");
    else puts("NO");
  }
  return 0;
}
