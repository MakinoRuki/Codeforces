#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 52
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string x, y;
    cin>>x>>y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    int i;
    for (i = 0; i < y.size(); ++i) {
      if (y[i] == '1') {
        break;
      }
    }
    int j;
    for (j = i; j < x.size(); ++j) {
      if (x[j] == '1') {
        break;
      }
    }
    printf("%d\n", j-i);
  }
  return 0;
}
