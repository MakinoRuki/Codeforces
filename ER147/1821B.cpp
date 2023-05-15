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
#define N 200005
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    int l=n+1, r=0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] != b[i]) {
        l = min(l, i);
        r = max(r, i);
      }
    }
    while(l -1 >= 1 && b[l-1] <= b[l]) {
      l--;
    }
    while(r + 1 <= n && b[r] <= b[r+1]) {
      r++;
    }
    printf("%d %d\n",l, r);
  }
  return 0;
}
