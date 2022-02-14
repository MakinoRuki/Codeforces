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
#define M 202
#define N 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int x;
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      ss.insert(x);
    }
    int sz = (int)ss.size();
    if (sz != 1) {
      puts("1");
    } else {
      printf("%d\n", n);
    }
  }
  return 0;
}
