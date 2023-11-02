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
#define N 300005
#define M 510
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int tot=0;
    int ans=0;
    map<int, int> ps;
    ps.clear();
    for (int i = 1; i <= n; ++i) {
      int x = a[i];
      for (int j = 2; j * j <= x; ++j) {
        if (x % j == 0) {
          int cnt=0;
          while(x%j == 0) {
            x/=j;
            cnt++;
          }
          ps[j] += cnt;
        }
      }
      if (x > 1) ps[x]++;
    }
    for (auto itr : ps) {
      ans += itr.second/2;
      if (itr.second%2) tot++;
    }
    ans += tot/3;
    printf("%d\n", ans);
  }
  return 0;
}
