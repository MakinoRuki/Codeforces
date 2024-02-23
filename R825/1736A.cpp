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
#define N 5010
#define M 15
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
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    int a0=0,b0=0;
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] == 0) a0++;
      if (b[i] == 0) b0++;
      if (a[i] != b[i]) cnt++;
    }
    int dt=abs(a0-b0);
    if (dt == cnt) {
      printf("%d\n", dt);
    } else {
      printf("%d\n", dt+1);
    }
  }
  return 0;
}
