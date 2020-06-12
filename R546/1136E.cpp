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
#define N 100005
#define M 100005
#define inf 1000000000
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, q;
ll a[N], k[N];
ll sum[N];
struct node {
  int l, r;
  ll sum, val;
} tree[2][N<<2];
void build(int id, int rt, int l, int r) {
  tree[id][rt].l = l;
  tree[id][rt].r = r;
  tree[id][rt].val = -(1LL<<61);
  tree[id][rt].sum = 0LL;
  if (l == r) {
    tree[id][rt].sum = (id ? k[l] : a[l]);
    tree[id][rt].val = (id ? k[l] : a[l]);
    return ;
  }
  int mid=(l+r)/2;
  build(id, rt*2, l, mid);
  build(id, rt*2+1, mid+1, r);
  tree[id][rt].sum = tree[id][rt*2].sum+tree[id][rt*2+1].sum;
}
void update(int id, int rt, int l, int r, ll x) {
  if (tree[id][rt].l == l && tree[id][rt].r == r) {
    tree[id][rt].val = x;
    ll det = r-l+1;
    tree[id][rt].sum = det * x;
    return;
  }
  int mid = (tree[id][rt].l+tree[id][rt].r)/2;
  if (tree[id][rt].val > -(1LL<<61)) {
    tree[id][rt*2].val = tree[id][rt].val;
    tree[id][rt*2+1].val = tree[id][rt].val;
    tree[id][rt*2].sum = (mid-tree[id][rt].l+1)*tree[id][rt*2].val;
    tree[id][rt*2+1].sum = (tree[id][rt].r-mid)*tree[id][rt*2+1].val;
    tree[id][rt].val = -(1LL<<61);
  }
  if (r <= mid) {
    update(id, rt*2, l, r, x);
  } else if (l > mid) {
    update(id, rt*2+1, l, r, x);
  } else {
    update(id, rt*2, l, mid, x);
    update(id, rt*2+1, mid+1, r, x);
  }
  tree[id][rt].sum = tree[id][rt*2].sum + tree[id][rt*2+1].sum;
}
ll query(int id, int rt, int l, int r) {
  if (tree[id][rt].l == l && tree[id][rt].r == r) {
    return tree[id][rt].sum;
  }
  int mid = (tree[id][rt].l+tree[id][rt].r)/2;
  if (tree[id][rt].val > -(1LL<<61)) {
    tree[id][rt*2].val = tree[id][rt].val;
    tree[id][rt*2+1].val = tree[id][rt].val;
    tree[id][rt*2].sum = (mid-tree[id][rt].l+1)*tree[id][rt*2].val;
    tree[id][rt*2+1].sum = (tree[id][rt].r-mid)*tree[id][rt*2+1].val;
    tree[id][rt].val = -(1LL<<61);
  }
  if (r <= mid) return query(id, rt*2, l, r);
  else if (l > mid) return query(id, rt*2+1, l, r);
  else {
    return query(id, rt*2, l, mid) + query(id, rt*2+1, mid+1, r);
  }
}
void solve(int id, ll x) {
 // if (id==1 && x==2) cout<<"p="<<query(0,1,id,id)<<" "<<k[id]<<" "<<query(1,1,id,id)<<endl;
  ll cur = query(0, 1, id, id) + k[id] - query(1, 1, id, id);
  int id1 = id, id2 = n;
  while(id1 < id2) {
    int mid = (id1+id2+1)/2;
    ll tmp = query(0, 1, mid, mid) + k[mid] - query(1, 1, mid, mid);
    if (id==1 && x==2) {
     // cout<<"w="<<cur<<" "<<mid<<" "<<tmp<<endl;
    }
    if (cur + x + k[mid] - k[id] <= tmp) {
      id2 = mid-1;
    } else {
      id1 = mid;
    }
  }
 // if (id==1&&x==2) cout<<"id="<<id<<" "<<id2<<" "<<cur+x<<endl;
  update(0, 1, id, id2, cur+x);
  //if (id==1&&x==2) cout<<"val="<<query(0,1,1,1)<<" "<<query(0, 1, 2, 2)<<endl;
  update(1, 1, id, id2, k[id]);
}
int main() {
  cin>>n;
  for (int i = 1 ; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  memset(k, 0LL, sizeof(k));
  memset(sum, 0LL, sizeof(sum));
  for (int i = 2; i <= n; ++i) {
    scanf("%lld", &k[i]);
    k[i] += k[i-1];
    sum[i] = sum[i-1] + k[i];
  }
  build(0, 1, 1, n);
  build(1, 1, 1, n);
 // update(0, 1, 1, 2, 3);
//  cout<<"v1="<<query(0,1,2,2)<<" "<<query(0, 1, 1, 1)<<endl;
 // cout<<"v2="<<query(0, 1, 2, 2)<<endl;
 // cout<<"z2="<<query(0, 1, 1, 1)<<endl;
  cin>>q;
  for (int i = 1; i <= q; ++i) {
    string op;
    cin>>op;
    if (op=="s") {
      int l, r;
      scanf("%d%d",&l,&r);
      ll ans = query(0, 1, l, r) + sum[r] - sum[l-1] - query(1, 1, l, r);
      //if (i==q) cout<<query(0,1,l,r)<<" "<<sum[r]-sum[l-1]<<" "<<query(1,1,l,r)<<endl;
     // if (i==q) cout<<l<<" "<<r<<" "<<query(0, 1, l, l)<<" "<<query(0, 1, r, r)<<endl;
      printf("%lld\n", ans);
    } else {
      int id;
      ll x;
      scanf("%d%lld", &id, &x);
      solve(id, x);
    }
   // cout<<"val2="<<query(0,1,1,1)<<" "<<query(0,1,2,2)<<endl;
   // if (i==4) cout<<"w="<<query(0, 1, 2,2)<<" "<<query(1,1,2,2)<<endl;
    //cout<<"z="<<query(0, 1, 1, 1)<<" "<<query(0, 1, 2,2)<<" "<<query(1,1,2,2)<<endl;
  }
  return 0;
}
