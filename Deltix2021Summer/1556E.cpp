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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int t,q;
ll a[N], b[N];
ll pre[N];
struct node {
  int l, r;
  ll mx, mn;
} tree[N<<2];
void build(int id, int l, int r) {
  tree[id].l = l;
  tree[id].r = r;
  if (l == r) {
    tree[id].mx = pre[l];
    tree[id].mn = pre[l];
    return;
  }
  int mid = (l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  tree[id].mx = max(tree[id*2].mx, tree[id*2+1].mx);
  tree[id].mn = min(tree[id*2].mn, tree[id*2+1].mn);
}
ll query(int id, int l, int r, bool mx) {
 // cout<<"v="<<id<<" "<<l<<" "<<r<<endl;
  if (tree[id].l == l && tree[id].r == r) {
    return (mx ? tree[id].mx : tree[id].mn);
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (r <= mid) return query(id*2, l, r, mx);
  else if (l > mid) return query(id*2+1, l, r, mx);
  else {
    ll r1 = query(id*2, l, mid, mx);
    ll r2 = query(id*2+1, mid+1, r, mx);
    return (mx ? max(r1,r2) : min(r1,r2));
  }
}
int main() {
  cin>>n>>q;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &b[i]);
  }
  pre[0] = 0LL;
  for (int i = 1; i <= n; ++i) {
    pre[i] = pre[i-1] + b[i] - a[i];
  }
  build(1, 1, n);
  while(q-->0) {
    int l, r;
    scanf("%d%d", &l, &r);
  // cout<<pre[r]<<" "<<pre[l-1]<<" "<<query(1, l, r, false)<<endl;
    if (pre[r] - pre[l-1] != 0 || query(1, l, r, false) < pre[l-1]) {
      puts("-1");
    } else {
      printf("%lld\n", query(1, l, r, true) - pre[l-1]);
    }
  }
  return 0;
}
