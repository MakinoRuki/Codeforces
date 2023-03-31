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
#define N 100000
#define M 520
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int d[N];
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    bool found=false;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &d[i]);
    }
    for (int i =1; i <= n; ++i) {
      if (i == 1) a[i] = d[i];
      else if (a[i-1] - d[i] >= 0 && a[i-1]-d[i]!=a[i-1]+d[i]) {
        found=true;
        break;
      }
      a[i] = a[i-1] + d[i];
    }
    if (found) puts("-1");
    else {
      for (int i = 1; i <= n; ++i) {
        printf("%d", a[i]);
        if (i < n) cout<<" ";
        else cout<<endl;
      }
    }
  }
  return 0;
}
