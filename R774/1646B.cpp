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
#define N 200005
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
  for (int cas=1;cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i= 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    ll s1 = (ll)a[1]  +(ll)a[2];
    ll s2 = a[n];
    int l = 2, r = n;
    bool ok = false;
    while(true) {
      if (s1 < s2) {
        ok=true;
        break;
      }
      l++;
      r--;
      if (l < r) {
        s1 += (ll)a[l];
        s2 += (ll)a[r];
      } else {
        break;
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
