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
#include <list>
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    if (k > 3) {
      puts("0");
      continue;
    }
    if (k == 1) {
      puts("1");
      continue;
    }
    if (k == 3) {
      if (m > n) {
        int q = m/n;
        int dt = m-n-(q-1);
        printf("%d\n", dt);
      } else {
        puts("0");
      }
      continue;
    }
    int ans=m;
    if (m > n) {
      int q=m/n;
      int dt=m-n-(q-1);
      ans-=dt;
    }
    printf("%d\n", ans);
  }
  return 0;
}
