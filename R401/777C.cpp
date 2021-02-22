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
int n, m;
int a[N];
int k;
int len[N];
int main() {
  cin>>n>>m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i*m+j]);
    }
  }
  memset(len, -1, sizeof(len));
  cin>>k;
  for (int j = 0; j < m; ++j) {
    int id = 0;
    for (int i = 0; i < n; ++i) {
      if (i == 0 || a[i*m+j] >= a[(i-1)*m+j]) {
        len[id] = max(len[id], i);
      } else {
        id = i;
        len[id] = max(len[id], i);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i > 0) len[i] = max(len[i], len[i-1]);
  }
  while(k-->0) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    r--;
    if (len[l] >= r) {
      puts("Yes");
    } else {
      puts("No");
    }
  }
  return 0;
}
