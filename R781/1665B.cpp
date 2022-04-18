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
#define N 500005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    map<int, int> cnt;
    cnt.clear();
    for (int i=  1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    int mx = 0;
    for (auto itr : cnt) {
      mx = max(mx, itr.second);
    }
    int ans = 0;
    int cur = mx;
    while(cur < n) {
      cur *= 2;
      ans++;
    }
    ans += n - mx;
    printf("%d\n", ans);
  }
  return 0;
}
