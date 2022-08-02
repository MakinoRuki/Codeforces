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
#define M 100005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
bool check() {
  int sum=2+4+6+8;
  for (int i = 1; i < n; ++i) {
    vector<int> ds;
    ds.clear();
    int x = a[i];
    if ((x % 10) == 0 && a[i] != a[n]) {
      return false;
    }
    for (int j = 1; j <= 4; ++j) {
      ds.push_back(x%10);
      x += x%10;
    }
    for (int j = 1; j < ds.size(); ++j) {
      ds[j] += ds[j-1];
    }
    int dt = a[n] - a[i];
    int r = dt % sum;
    if (r == 0 || r == ds[0] || r == ds[1] || r == ds[2] || r == ds[3]) {
      continue;
    }
    return false;
  }
  return true;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] % 2) {
        a[i] += a[i]%10;
      }
    }
    sort(a+1, a+n+1);
    bool ok = false;
    int i;
    for (i = 1; i < n; ++i) {
      if (a[i] != a[i+1]) {
        break;
      }
    }
    if (i >= n) {
      puts("Yes");
      continue;
    }
    for (int i = 0; i <= 4; ++i) {
      if (check()) {
       // cout<<"i="<<i<<" "<<a[n]<<endl;
        ok=true;
        break;
      }
      a[n] += a[n]%10;
    }
    if (ok) puts("Yes");
    else puts("No");
  }
  return 0;
}
