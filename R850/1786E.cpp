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
#include <bitset>
#define N 500005
#define M 325
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
struct node {
  int l, r;
  int mn;
  int dt;
  int idx;
} tree[N<<2];
void pushup(int id) {
  if (tree[id*2].mn <= tree[id*2+1].mn) {
    tree[id].mn = tree[id*2].mn;
    tree[id].idx = tree[id*2].idx;
  } else {
    tree[id].mn = tree[id*2+1].mn;
    tree[id].idx = tree[id*2+1].idx;
  }
}
void pushdown(int id) {
  if (tree[id].dt != 0) {
    tree[id*2].dt += tree[id].dt;
    tree[id*2].mn += tree[id].dt;
    tree[id*2+1].dt += tree[id].dt;
    tree[id*2+1].mn += tree[id].dt;
    tree[id].dt = 0;
  }
}
void build(int id, int l, int r) {
  tree[id].l = l;
  tree[id].r = r;
  if (l == r) {
    tree[id].dt = 0;
    tree[id].mn = l;
    tree[id].idx = l;
    return;
  }
  int mid=(l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  pushup(id);
  tree[id].dt =0;
}
void update(int id, int l, int r, int dt) {
  if (tree[id].l == l && tree[id].r == r) {
    tree[id].mn += dt;
    tree[id].dt += dt;
    return;
  }
  pushdown(id);
  int mid=(tree[id].l+tree[id].r)/2;
  if (r <= mid) {
    update(id*2, l, r, dt);
  } else if (l > mid) {
    update(id*2+1, l, r, dt);
  } else {
    update(id*2, l, mid, dt);
    update(id*2+1, mid+1, r, dt);
  }
  pushup(id);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    build(1, 1, n);
    ll cnt=0;
    ll tot=0;
    for (int i = 1; i <= n; ++i) {
      update(1, a[i], n, -1);
      cnt++;
      tot += a[i];
     // cout<<"i="<<i<<" "<<tree[1].mn<<" "<<tree[1].idx<<endl;
      if (tree[1].mn < 0) {
        int id = tree[1].idx;
        cnt--;
        tot -= id;
        update(1, id, n, +1);
      }
      //设<=a[i]的数字已经出现x次，需要使得a[i]-x>=0。
      ll res = tot - cnt*(cnt+1)/2LL;
      printf("%lld ", res);
    }
    cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

