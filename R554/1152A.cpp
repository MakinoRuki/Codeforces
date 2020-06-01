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
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n, m;
int a[N], b[N];
int main() {
  cin>>n>>m;
  int ao = 0, ae = 0;
  int bo = 0, be = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] % 2) ao++;
    else ae++;
  }
  for (int j = 1; j <= m; ++j) {
    scanf("%d", &b[j]);
    if (b[j] % 2) bo++;
    else be++;
  }
  cout<<min(ao, be) + min(ae, bo)<<endl;
  return 0;
}
