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
#define N 200002
#define M 100
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
bool sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    sum[0] = true;
    int mx=0;
    int cur=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cur ^= a[i];
      for (int j = 1; j <= (1<<8); ++j) {
        if (sum[cur^j]) {
          mx = max(mx, j);
          //if (mx == 7) cout<<"i="<<i<<" "<<j<<endl;
        }
      }
      sum[cur] = true;
    }
    printf("%d\n", mx);
    cur = 0;
    sum[cur] = false;
    for (int i = 1; i <= n; ++i) {
      cur ^= a[i];
      sum[cur] = false;
    }
  }
  return 0;
}
