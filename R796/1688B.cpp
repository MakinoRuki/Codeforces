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
    bool found=false;
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] % 2) found=true;
      else cnt++;
    }
    if (found) {
      printf("%d\n", cnt);
    } else {
      int pw = -1;
      for (int i = 1; i <= n; ++i) {
        int x = a[i];
        int cnt=0;
        while(x%2==0) {
          x/=2;
          cnt++;
        }
        pw = (pw < 0 ? cnt : min(pw, cnt));
      }
      int ans = pw + n-1;
      printf("%d\n", ans);
    }
  }
  return 0;
}
