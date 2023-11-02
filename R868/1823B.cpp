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
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int cnt=0;
    for (int i = 1; i <= k; ++i) {
      set<int> ss;
      ss.clear();
      for (int j = i; j <= n; j += k) {
        ss.insert(a[j]);
      }
      for (int j = i; j <= n; j += k) {
        if (ss.find(j) == ss.end()) {
          cnt++;
        }
      }
    }
    if (cnt == 0) {
      puts("0");
    } else if (cnt == 2) {
      puts("1");
    } else {
      puts("-1");
    }
  }
  return 0;
}
