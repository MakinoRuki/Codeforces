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
#define N 300005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
int a[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  int l = 0, r = m;
  while(l < r) {
    int mid = (l+r)/2;
    int b[N];
    for (int i = 1; i <= n; ++i) {
      b[i] = a[i];
    }
    int i;
    b[0] = 0;
    for (i = 1; i <= n; ++i) {
      if (b[i] >= b[i-1]) {
        if (b[i]+mid >= m && (b[i]+mid)%m >= b[i-1]) {
          b[i] = b[i-1];
        }
      } else {
        if (b[i]+mid >= b[i-1]) {
          b[i] = b[i-1];
        } else {
          break;
        }
      }
    }
    if (i >= n) {
      for (i = 1; i <= n; ++i) {
        if (b[i] < b[i-1]) break;
      }
      if (i <= n) {
        l = mid+1;
      } else {
        r = mid;
      }
    } else {
      l = mid+1;
    }
  }
  cout<<r<<endl;
  return 0;
}
