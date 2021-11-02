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
#define M 21
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int q;
int a[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {

  // }
  cin>>n;
  bool found=false;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i]%2) found=true;
  }
  if (found) puts("First");
  else puts("Second");
  return 0;
}
