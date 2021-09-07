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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, q, k;
int a[N];
struct node {
  int l, r;
  int ls, rs;
  ll tot;
} tree[N<<2];
void pushup(int id, int mid) {
  tree[id].ls = tree[id*2].ls;
  tree[id].rs = tree[id*2+1].rs;
  tree[id].tot = tree[id*2].tot + tree[id*2+1].tot;
  if (a[mid]<=a[mid+1]) {
    if (tree[id].ls >= mid-tree[id].l+1) {
      tree[id].ls += tree[id*2+1].ls;
    }
    if (tree[id].rs >= tree[id].r - mid) {
      tree[id].rs += tree[id*2].rs;
    }
    tree[id].tot += (ll)tree[id*2].rs * (ll)tree[id*2+1].ls;
  }
}
void build(int id, int l, int r) {
  tree[id].l = l;
  tree[id].r = r;
  if (l == r) {
    tree[id].ls = 1;
    tree[id].rs = 1;
    tree[id].tot = 1LL;
    return ;
  }
  int mid=(l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  pushup(id, mid);
}
void update(int id, int x, int y) {
  if (tree[id].l == tree[id].r) {
    a[x] = y;
    return ;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (x <= mid) {
    update(id*2, x, y);
  } else {
    update(id*2+1, x, y);
  }
  pushup(id, mid);
}
ll query(int id, int l, int r) {
  if (tree[id].l == l && tree[id].r == r) {
    return tree[id].tot;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (r <= mid) {
    return query(id*2, l, r);
  } else if (l > mid) {
    return query(id*2+1, l, r);
  } else {
    ll res = query(id*2, l, mid) + query(id*2+1, mid+1, r);
  //  if (l == 1 && r == 7) cout<<"v="<<query(id*2, l, mid)<<" "<<query(id*2+1, mid+1, r)<<endl;
    if (a[mid] <= a[mid+1]) {
      int llen = min(tree[id*2].rs, mid-l+1);
      int rlen = min(tree[id*2+1].ls, r-mid);
      res += (ll)llen * (ll)rlen;
    }
    return res;
  }
}
int main() {
  cin>>n>>q;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  build(1, 1, n);
  while(q-->0) {
    int tp;
    scanf("%d", &tp);
    if (tp == 1) {
      int x, y;
      scanf("%d%d", &x, &y);
      update(1, x, y);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      ll res = query(1, l, r);
      // for (int i = 1; i <= n; ++i) {
      //   printf("%d ", a[i]);
      // }
      // cout<<endl;
      printf("%lld\n", res);
    }
  }
  return 0;
}
