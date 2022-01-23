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
#define M 500005
#define N 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q, p;
int l, r;
int t;
string s;
int bit[4][11][11][N];
int lowbit(int x) {
  return x&(-x);
}
void update(int d, int mm, int rr, int pos, int v) {
  while(pos <= n) {
    bit[d][mm][rr][pos] += v;
    pos += lowbit(pos);
  }
}
int query(int d, int mm, int rr, int pos) {
  int res=0;
  while(pos) {
    res += bit[d][mm][rr][pos];
    pos -= lowbit(pos);
  }
  return res;
}
int getd(char c) {
  if (c == 'A') return 0;
  if (c == 'T') return 1;
  if (c == 'G') return 2;
  return 3;
}
int main() {
  cin>>s;
  cin>>q;
  memset(bit, 0, sizeof(bit));
  n = (int)s.size();
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 1; j <= 10; ++j) {
      int d = getd(s[i]);
      int r = (i+1) % j;
      // if (d ==0 && j== 4 && r == 1) {
      //   cout<<"x="<<i+1<<endl;
      // }
      update(d, j, r, i+1, 1);
    }
  }
//  cout<<"v="<<query(0, 4, 1, n)<<endl;
  while(q-->0) {
    int ty;
    scanf("%d", &ty);
    if (ty == 1) {
      int x;
      scanf("%d", &x);
      string e;
      cin>>e;
      int d = getd(e[0]);
      int d2 = getd(s[x-1]);
      for (int j = 1; j <= 10; ++j) {
        int r = x % j;
        update(d2, j, r, x, -1);
        update(d, j, r, x, 1);
      }
      s[x-1] = e[0];
    } else {
      scanf("%d%d", &l, &r);
      string e;
      cin>>e;
      int len = (int)e.size();
      int tot=0;
      for (int i = 0; i < e.size(); ++i) {
        int d = getd(e[i]);
        int rr = (l+i) % len;
        tot += query(d, len, rr, r) - query(d, len, rr, l-1);
      }
      printf("%d\n", tot);
    }
  }
  return 0;
}
