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
#define M 20
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
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int res=a[1];
  for (int i = 2; i <= n; ++i) {
    b[i] = res;
    res ^= a[i];
  }
  b[1] = 0;
  for (int i = 20; i >= 0; --i) {
    int cnt=0;
    for (int j = 0; j < n; ++j) {
      if ((1<<i) & j) cnt++;
    }
    int cnt2=0;
    for (int j = 2; j <= n; ++j) {
      if ((1<<i) & b[j]) cnt2++;
    }
    if (cnt != cnt2) {
      b[1] |= (1<<i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (i > 1) b[i] ^= b[1];
    printf("%d ", b[i]);
  }
  cout<<endl;
  return 0;
}
