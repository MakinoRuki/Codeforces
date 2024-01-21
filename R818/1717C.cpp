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
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N], b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    bool found=false;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
        if (a[i] > b[i]) {
            found=true;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int x = b[i];
        int y = (i == n ? b[1] : b[i+1]);
        if (x - y > 1 && a[i] != b[i]) {
            found=true;
            break;
        }
    }
    if (found) puts("NO");
    else puts("YES");
  }
  return 0;
}
