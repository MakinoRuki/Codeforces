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
#include <ctime>
#include <list>
#include <stack>
#define N 300005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int xv[N], vv[N];
int lh[N], rh[N];
struct node {
  int l, r;
  ll vl = 0LL, vr = 0LL;
  ll sum = 0LL;
  ll v;
  ll res;
} tree[N<<2];
// 线段树的pushup/pushdown操作：每个节点有原值val和更新值dt
// pushdown时把父亲的dt给儿子同时更新儿子的val和dt，父亲的dt清0
// pushup的时候用儿子的原值val更新父亲的val
void pushdown(int id) {
  int ll = tree[id*2].r-tree[id*2].l+1;
  int rr = tree[id*2+1].r - tree[id*2+1].l+1;
  if (tree[id].vl) {
    tree[id*2].vl += tree[id].vl;
    tree[id*2].v += ll * tree[id].vl;
    tree[id*2].res += tree[id*2].sum * tree[id].vl;
    tree[id*2+1].vl += tree[id].vl;
    tree[id*2+1].v += rr * tree[id].vl;
    tree[id*2+1].res += tree[id*2+1].sum * tree[id].vl;
    tree[id].vl = 0;
  }
  if (tree[id].vr) {
    tree[id*2].vr += tree[id].vr;
    tree[id*2].sum += ll * tree[id].vr;
    tree[id*2].res += tree[id*2].v * tree[id].vr;
    tree[id*2+1].vr += tree[id].vr;
    tree[id*2+1].sum += rr * tree[id].vr;
    tree[id*2+1].res += tree[id*2+1].v * tree[id].vr;
    tree[id].vr = 0;
  }
}
void pushup(int id) {
  tree[id].res = tree[id*2].res + tree[id*2+1].res;
  tree[id].sum = tree[id*2].sum + tree[id*2+1].sum;
  tree[id].v = tree[id*2].v + tree[id*2+1].v;
}
void build(int id, int l, int r) {
  tree[id].l = l;
  tree[id].r = r;
  if (l == r) {
    tree[id].vl = 0, tree[id].vr = 0;
    tree[id].v = a[lh[l]];
    tree[id].sum = rh[l]-l;
    tree[id].res = tree[id].sum * tree[id].v;
    return;
  }
  int mid=(l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  pushup(id);
}
void update(int id, int l, int r, int tp, ll dt) {
  if (tree[id].l == l && tree[id].r == r) {
    ll len = tree[id].r - tree[id].l + 1;
    // 区间update也要update原值而不是只有dt。
    if (tp) {
      tree[id].vr += dt;
      tree[id].sum += len * dt;
      tree[id].res += tree[id].v * dt;
    } else {
      tree[id].vl += dt;
      tree[id].v += len * dt;
      tree[id].res += tree[id].sum * dt;
    }
    return;
  }
  pushdown(id);
  int mid=(tree[id].l+tree[id].r)/2;
  if (r <= mid) {
    update(id*2, l, r, tp, dt);
  } else if (l > mid) {
    update(id*2+1, l, r, tp, dt);
  } else {
    update(id*2, l, mid, tp, dt);
    update(id*2+1, mid+1, r, tp, dt);
  }
  pushup(id);
}
ll query(int id, int l, int r) {
  //cout<<"id="<<id<<" "<<l<<" "<<r<<endl;
  if (tree[id].l == l && tree[id].r == r) {
    return tree[id].res;
   // ll len = tree[id].r - tree[id].l + 1;
   // ll res = (tree[id].sum + len * tree[id].vr) * (tree[id].v + tree[id].vl);
    //cout<<"id2="<<id<<" "<<res<<endl;
    //return res;
  }
  pushdown(id);
  int mid=(tree[id].l+tree[id].r)/2;
  ll ans = 0LL;
  if (r <= mid) {
    ans = query(id*2, l, r);
  } else if (l > mid) {
    ans = query(id*2+1, l, r);
  } else {
    ans = query(id*2, l, mid) + query(id*2+1, mid + 1, r);
  }
 // pushup(id);
 // cout<<"id2="<<id<<" "<<ans<<endl;
  return ans;
}
int main() {
  cin>>n>>m>>q;
  set<int> ss;
  ss.clear();
  for (int i = 1; i <= n; ++i) {
    a[i] = 0;
  }
  for (int i= 1; i <= m; ++i) {
    int x;
    scanf("%d", &xv[i]);
    ss.insert(xv[i]);
  }
  for (int i = 1; i <= m; ++i) {
    int v;
    scanf("%d", &vv[i]);
    a[xv[i]] = vv[i];
  }
  for (int i = 1; i <= n; ++i) {
    lh[i] = lh[i-1];
    if (a[i]) lh[i] = i;
  }
  for (int i = n; i >= 1; --i) {
    rh[i] = rh[i+1];
    if (a[i]) rh[i] = i;
  }
  build(1, 1, n);
//  cout<<"v="<<tree[5].res<<" "<<tree[10].res<<" "<<tree[11].res<<endl;
  while(q-->0) {
    ll tp;
    scanf("%lld", &tp);
    if (tp == 1) {
      ll x,v;
      scanf("%lld%lld", &x, &v);
      auto itr = ss.upper_bound(x);
      auto itr2 = itr;
      itr2--;
      int rb = *itr;
      int lb = *itr2;
      a[x] = v;
      ss.insert(x);
      // cout<<"u="<<lb+1<<" "<<x<<" "<<-(rb-x)<<endl;
      // cout<<"v="<<x+1<<" "<<rb-1<<" "<<-a[lb]+v<<endl;
      if (x <= rb-1) update(1, x, rb-1, 0, -a[lb]+v);
      if (lb +1 <= x) update(1, lb+1, x, 1, -(rb-x)); 
    } else {
      ll l,r;
      scanf("%lld%lld", &l, &r);
      ll ans = query(1, l, r);
      printf("%lld\n", ans);
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
 
