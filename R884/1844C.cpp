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
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i= 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int l =1, r=n;
    while(l <= n && a[l] < 0) {
      l++;
    }
    while(r >= 1 && a[r] < 0) {
      r--;
    }
    if (l > r) {
      int mx=a[1];
      for (int i =2; i <= n; ++i) {
        mx=max(mx, a[i]);
      }
      printf("%d\n", mx);
    } else {
      ll s0=0LL,s1=0LL;
      for (int i = l; i <= r; ++i) {
        if (i % 2) {
          if (a[i] >= 0) {
            s1+=a[i];
          }
        } else {
          if (a[i] >= 0) {
            s0 += a[i];
          }
        }
      }
      printf("%lld\n", max(s0, s1));
    }
  }
  return 0;
}
