
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
#include <chrono>
#define N 600005
#define M 5002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int rr[N];
int rr2[N];
int bit[N];
struct node {
  int l, r;
  int val;
} tree[N<<2];
void build(int id, int l, int r) {
  tree[id].l=l, tree[id].r=r;
  int mid=(l+r)/2;
  if (l == r) {
    tree[id].val=n+1;
    if (rr2[r] <= n) {
      tree[id].val = rr2[r];
    }
    return;
  }
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  tree[id].val = min(tree[id*2].val, tree[id*2+1].val);
}
int query(int id, int l, int r) {
//  cout<<"id="<<id<<" "<<l<<" "<<r<<" "<<tree[id].l<<" "<<tree[id].r<<endl;
  if (tree[id].l == l && tree[id].r == r) {
    return tree[id].val;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (r <= mid) {
    return query(id*2, l, r);
  } else if (l > mid) {
    return query(id*2+1, l, r);
  } else {
    return min(query(id*2, l, mid), query(id*2+1, mid+1, r));
  }
}
int lowbit(int x) {
  return x&(-x);
}
int bquery(int x) {
  if (x <= 0) return n+1;
  int res=n+1;
  while(x) {
    res=min(res, bit[x]);
    x -= lowbit(x);
  }
  return res;
}
void update(int x, int v) {
  while(x <= n) {
    bit[x] = min(bit[x], v);
    x += lowbit(x);
  }
}
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    int q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      rr[i] = n+1;
    }
    vector<int> v;
    v.clear();
    for (int i = n; i >= 1; --i) {
      while(!v.empty() && a[i] < a[v.back()]) {
        v.pop_back();
      }
      if (!v.empty()) {
        rr[i] = v.back();
      }
      v.push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
      bit[i] = n+1;
    }
    for (int i = n; i >= 1; --i) {
      auto res = bquery(a[i]-1);
      rr2[i] = res;
      update(a[i], rr[i]);
    }
    build(1, 1, n);
    vector<pair<int,int>> sg;
    sg.clear();
    for (int i = 1; i <= q; ++i) {
      int l,r;
      scanf("%d%d", &l, &r);
      int res=query(1, l, r);
      if (res <= r) {
        puts("No");
      } else {
        puts("Yes");
      }
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
