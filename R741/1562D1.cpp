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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int t,q;
string s;
int sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    cin>>s;
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i-1];
      int cur = (s[i-1] == '+' ? 1 : -1);
      if (i%2 == 0) cur *= -1;
      sum[i] += cur;
    }
    while(q-->0) {
      int l, r;
      scanf("%d%d", &l, &r);
      int res = sum[r] - sum[l-1];
      if (res == 0) {
        puts("0");
      } else if ((r-l+1) % 2) {
        puts("1");
      } else {
        puts("2");
      }
    }
  }
  return 0;
}
