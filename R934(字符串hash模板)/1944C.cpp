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
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) {
      cnt[i] = 0;
    }
    for (int i= 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      cnt[x]++;
    }
    int ans=0;
    for (int i = 0; i <= n; ++i) {
      if (cnt[i] == 0) {
        ans=i;
        break;
      }
    }
    int num=0;
    for (int i = 0; i < ans; ++i) {
      if (cnt[i] == 1) {
        num++;
        if (num == 2) {
          ans=i;
          break;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
