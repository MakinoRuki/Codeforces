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
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int l = 1, r = n;
    while(l < r) {
      int mid= (l+r)/2;
      printf("? %d %d\n", l, mid);
      fflush(stdout);
      int cnt=0;
      for (int i = 1; i <= mid-l+1; ++i) {
        int x;
        scanf("%d", &x);
        if (x >= l && x <= mid) {
          cnt++;
        }
      }
      if (cnt % 2) {
        r = mid;
      } else {
        l = mid+1;
      }
    }
    printf("! %d\n", r);
    fflush(stdout);
  }
  return 0;
}
