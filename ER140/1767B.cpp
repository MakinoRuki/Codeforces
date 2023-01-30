#include <iostream>
#include <cstdio>
#include <stdio.h>
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
#include <cstring>
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
ll a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<int> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      if (i > 1 && a[i] > a[1]) {
        rk.push_back(a[i]);
      }
    }
    sort(rk.begin(), rk.end());
    for (int i = 0; i < rk.size(); ++i) {
      if (rk[i] > a[1]) {
        ll dt = rk[i] - a[1];
        if (dt % 2) {
          dt = (dt+1)/2;
          a[1] += dt;
        } else {
          dt /= 2;
          a[1] += dt;
        }
      }
    }
    printf("%lld\n", a[1]);
  }
  return 0;
}
