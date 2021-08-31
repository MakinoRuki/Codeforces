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
struct node {
  int l, r;
  int val;
} tree[N<<2];
int sum[N];
int query(int l, int r, int sv) {
  if (l == r) {
    return l;
  }
  int mid = (l+r)/2;
  if (sv > 0) {
    if (sum[mid]-sum[l-1] >= sv) {
      return query(l, mid, sv);
    } else {
      return query(mid+1, r, sv-(sum[mid]-sum[l-1]));
    }
  } else {
    if (sum[mid] - sum[l-1] <= sv) {
      return query(l, mid, sv);
    } else {
      return query(mid+1, r, sv-(sum[mid]-sum[l-1]));
    }
  }
}
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
   // build(1, 1, n);
    while(q-->0) {
      int l, r;
      scanf("%d%d", &l, &r);
      int res = sum[r] - sum[l-1];
      if (res == 0) {
        puts("0");
      } else if ((r-l+1) % 2) {
        puts("1");
        if (res > 0) {
          printf("%d\n", query(l, r, res/2+1));
        } else {
          res = (abs(res)/2);
          if (res > 0) res = -res;
          res--;
          printf("%d\n", query(l, r, res));
        }
      } else {
        puts("2");
        if (res > 0) {
          printf("%d %d\n", query(l, r, 1), query(l, r, res/2+1));
        } else {
          res = abs(res)/2;
          printf("%d %d\n", query(l, r, -1), query(l, r, -res-1));
        }
      }
    }
  }
  return 0;
}
