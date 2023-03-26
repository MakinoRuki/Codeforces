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
int b[N];
int sum[N];
int idx(int x, int y) {
  if (x <= 0 || y <=0) return 0;
  return (x-1) * m + y;
}
bool check(int x) {
  for (int i = 1; i <= n*m; ++i) {
    b[i] = 0;
    if (a[i] >= x) {
      b[i] = 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      sum[idx(i,j)] = sum[idx(i-1,j)] + sum[idx(i, j-1)] - sum[idx(i-1, j-1)] + b[idx(i,j)];
    }
  }
  for (int i = 1; i + x - 1 <= n; ++i) {
    for (int j = 1; j + x -1 <= m; ++j) {
      int tot = sum[idx(i+x-1, j+x-1)] - sum[idx(i-1, j+x-1)] - sum[idx(i+x-1, j-1)] + sum[idx(i-1,j-1)];
      if (tot >= x * x) return true;
    }
  }
  return false;
}
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    //ll n;
    scanf("%d%d", &n, &m);
  //  cout<<getres(n)<<" "<<getres(n-1)<<endl;
    for (int i = 1; i <= n*m; ++i) {
      scanf("%d", &a[i]);
    }
    int l = 0, r = max(n, m);
    while(l < r) {
      int mid = (l+r+1)/2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid-1;
      }
    }
    printf("%d\n", r);
  }
  return 0;
}
