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
#define M 2000005
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
int t;
int a[N][5];
int q;
struct node {
  int l, r;
  int val[1<<5];
} tree[N<<2];
void build(int id, int l, int r) {
  tree[id].l=l;
  tree[id].r=r;
  if (l == r) {
    for (int i = 0; i < (1<<k); ++i) {
      tree[id].val[i] = 0;
      for (int j = 0; j < k; ++j) {
        if ((1<<j) & i) tree[id].val[i] += a[l][j];
        else tree[id].val[i] -= a[l][j];
      }
    }
    return ;
  }
  int mid=(l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  for (int i = 0; i < (1<<k); ++i) {
    tree[id].val[i] = max(tree[id*2].val[i], tree[id*2+1].val[i]);
  }
}
void update(int id, int pos) {
  if (tree[id].l==tree[id].r) {
    for (int i = 0; i < (1<<k); ++i) {
      tree[id].val[i] = 0;
      for (int j = 0; j < k; ++j) {
        if ((1<<j) & i) tree[id].val[i] += a[pos][j];
        else tree[id].val[i] -= a[pos][j];
      }
    }
    return;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (pos<=mid) update(id*2, pos);
  else update(id*2+1, pos);
  for (int i = 0; i < (1<<k); ++i) {
    tree[id].val[i] = max(tree[id*2].val[i], tree[id*2+1].val[i]);
  }
}
int query(int id, int l, int r, int st) {
  if (tree[id].l==l && tree[id].r==r) {
    return tree[id].val[st];
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (r<=mid) return query(id*2, l, r, st);
  else if (l > mid) return query(id*2+1, l, r, st);
  else return max(query(id*2, l, mid, st), query(id*2+1, mid+1, r, st));
}
int main() {
  cin>>n>>k;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < k; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  build(1, 1, n);
  cin>>q;
  while(q-->0) {
    int tp;
    scanf("%d", &tp);
    if (tp == 1) {
      int id;
      scanf("%d", &id);
      for (int i = 0; i < k; ++i) {
        scanf("%d", &a[id][i]);
      }
      update(1, id);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      int res = -inf;
      for (int i = 0; i < (1<<k); ++i) {
        res = max(res, query(1, l, r, i) + query(1, l, r, ((1<<k)-1)^i));
     //   cout<<i<<" "<<res<<endl;
      }
      printf("%d\n", res);
    }
  }
  return 0;
}
