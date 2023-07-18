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
#define N 600005
#define M 22
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
vector<int> sg[N];
int sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      sg[i].clear();
      a[i] = n+2;
    }
    for (int i = 1; i <= m; ++i) {
      int l, r;
      scanf("%d%d", &l, &r);
      sg[r].push_back(l);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
      int x;
      scanf("%d", &x);
      a[x] = i;
    }
    int l = 0, r = q+1;
    while(l < r) {
      int mid = (l+r)/2;
      sum[0] = 0;
      for (int i = 1; i <= n; ++i) {
        if (a[i] <= mid) {
          sum[i] = sum[i-1] + 1;
        } else {
          sum[i] = sum[i-1] - 1;
        }
      }
      bool found=false;
      for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < sg[i].size(); ++j) {
          int ll = sg[i][j];
          if (sum[i] - sum[ll-1] > 0) {
            found=true;
            break;
          }
        }
        if (found) break;
      }
      if (found) {
        r = mid;
      } else {
        l = mid+1;
      }
    }
    if (r <= q) {
      printf("%d\n", r);
    } else {
      puts("-1");
    }
  }
  return 0;
}
