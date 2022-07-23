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
#define N 200005
#define M 300005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
struct node {
  int l, r;
  int mx;
} tree[N<<2];
void build(int id, int l, int r) {
  tree[id].l = l;
  tree[id].r = r;
  if (l == r) {
    tree[id].mx = a[l];
    return;
  }
  int mid=(l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  tree[id].mx = max(tree[id*2].mx, tree[id*2+1].mx);
}
int query(int id, int l, int r) {
  if (tree[id].l == l && tree[id].r == r) {
    return tree[id].mx;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (r <= mid) {
    return query(id*2, l, r);
  } else if (l > mid) {
    return query(id*2+1, l, r);
  } else {
    return max(query(id*2, l, mid), query(id*2+1, mid+1, r));
  }
}
//int sum[3][N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &a[i]);
  }
  build(1, 1, m);
//  cout<<"??"<<endl;
  scanf("%d", &q);
  while(q-->0) {
    ll x1, y1, x2, y2;
    ll k;
    scanf("%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &k);
    if (y1 > y2) {
      swap(x1, x2);
      swap(y1, y2);
    }
    ll res = query(1, y1, y2);
    if (res >= n) {
      puts("NO");
    } else {
      res++;
      if (x1 < res) {
        ll d1 = (res-x1+k-1)/k;
        x1 += d1 * k;
      }
      if (x2 < res) {
        ll d2 = (res-x2+k-1)/k;
        x2 += d2 * k;
      }
      if (x1 > n || x2 > n) {
        puts("NO");
        continue;
      }
      if ((abs(x1-x2) % k == 0) && (abs(y1-y2)%k == 0)) {
        puts("YES");
      } else {
        puts("NO");
      }
    }
  }
  return 0;
}
