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
#define N 200005
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int x[N];
int y[N];
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &x[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &y[i]);
    }
    int ans=0;
    vector<int> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      rk.push_back(y[i] - x[i]);
    }
    sort(rk.begin(), rk.end());
    int l = 0, r = (int)rk.size()-1;
    while(l < r) {
      if (rk[r] + rk[l] >= 0) {
        ans++;
        l++;
        r--;
      } else {
        l++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
