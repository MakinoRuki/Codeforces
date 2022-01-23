#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 52
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int q;
int a[N];
int b[N];
int sum[N];
int c1[30];
int c2[N];
int main() {
  for (int i = 0; i < N; ++i) {
    c2[i] = inf;
    for (int j = 0; j <= 20; ++j) {
      if ((1<<j) >= i) {
        c2[i] = min(c2[i], (1<<j)-i);
      }
    }
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      b[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      b[a[i]]++;
    }
    b[0] = 0;
    sum[0] = 0;
    for (int i =1; i <= n; ++i) {
      sum[i] = sum[i-1] + b[i];
    }
    int cur = 0;
    for (int i = 0; i <= 20; ++i) {
      while(cur <= n && sum[cur] <= (1<<i)) {
        cur++;
      }
      c1[i] = cur-1;
    }
    int l = 0, r = 1000000;
    while(l < r) {
      int mid = (l+r)/2;
      int tot=0;
      bool found=false;
      for (int i = n; i >= 0; --i) {
        int x = sum[n] - sum[i];
        x = c2[x];
        for (int j = 0; j <= 20; ++j) {
          if (c1[j] <= i) {
            int y  = c2[sum[c1[j]]];
            int z  = c2[sum[i]-sum[c1[j]]];
            if (x + y + z <= mid) {
           //   if (mid == 1) cout<<"v="<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<z<<endl;
              found=true;
              break;
            }
          }
        }
        if (found) break;
      }
      if (found) {
        r = mid;
      } else {
        l = mid+1;
      }
    }
    printf("%d\n", r);
  }
  return 0;
}
