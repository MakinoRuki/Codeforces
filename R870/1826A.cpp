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
#define N 2000005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
int a[N];
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    //ll n;
    scanf("%d", &n);
    for (int i = 0; i <= n+2; ++i) {
      a[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      a[x]++;
    }
    for (int i = n-1; i >= 0; --i) {
      a[i] += a[i+1];
    }
    int ans=-1;
    for (int i = 0; i <= n; ++i) {
      if (a[i+1] == i) {
        ans=i;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
