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
#define M 3000000
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q, p;
int t;
int a[N];
ll ls[N], rs[N];
struct node {
  int l, r;
  ll s[2];
} tree[N<<2];
void build(int id, int l, int r) {
  tree[id].l=l;
  tree[id].r=r;
  if (l==r) {
    tree[id].s[0] = ls[l];
    tree[id].s[1] = rs[l];
    return;
  }
  int mid=(l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  tree[id].s[0] = min(tree[id*2].s[0], tree[id*2+1].s[0]);
  tree[id].s[1] = min(tree[id*2].s[1], tree[id*2+1].s[1]);
}
ll query(int id, int l, int r, int x) {
  if (tree[id].l==l && tree[id].r==r) {
    return tree[id].s[x];
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (r <= mid) {
    return query(id*2, l, r, x);
  } else if (l > mid) {
    return query(id*2+1, l, r, x);
  } else {
    return min(query(id*2, l, mid, x), query(id*2+1, mid+1, r, x));
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<int> ids;
    ids.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] > 0) {
        ids.push_back(i);
      }
    }
    bool ok = true;
    ll sum=0LL;
    for (int i = 1; i < n; ++i) {
      if (a[i] > 0 && a[i+1] > 0) {
        ok=false;
        break;
      }
    }
    if (!ok) {
      puts("NO");
      continue;
    }
    ls[0] = 0LL;
    for (int i =1 ; i <= n; ++i) {
      ls[i] = ls[i-1]+a[i];
    }
    rs[n+1] = 0LL;
    for (int i = n; i >= 1; --i) {
      rs[i] = rs[i+1] + a[i];
    }
    build(1, 1, n);
    vector<int> stk;
    stk.clear();
    for (int i = 0; i < ids.size(); ++i) {
    //  cout<<"i="<<i<<endl;
      while(!stk.empty() && a[ids[i]] >= a[stk.back()]) {
        stk.pop_back();
      }
      int id= ids[i];
      if (!stk.empty()) {
        int id1 = stk.back();
        auto res = query(1, id1, id-1, 0);
        if (ls[id]-res > a[id]) {
          ok=false;
          break;
        }
      } else {
        if ((id-1>=1 && ls[id]-query(1, 1, id-1,0)>a[id]) || ls[id] > a[id]) {
          ok=false;
          break;
        }
      }
   //   cout<<"i="<<i<<endl;
      stk.push_back(id);
    }
    stk.clear();
    for (int i = ids.size()-1; i >= 0; --i) {
    //  cout<<"i2="<<i<<endl;
      while(!stk.empty() && a[ids[i]] >= a[stk.back()]) {
        stk.pop_back();
      }
      int id = ids[i];
      if (!stk.empty()) {
        int id2 = stk.back();
     //   cout<<"i3="<<i<<endl;
        auto res = query(1, id+1, id2, 1);
      //  cout<<"i3="<<i<<endl;
        if (rs[id] - res > a[id]) {
          ok=false;
          break;
        }
      } else {
      //  cout<<"i4="<<i<<endl;
      //  auto res = query(1, id+1, n, 1);
      //  cout<<"i4="<<i<<endl;
        if ((id+1<=n && rs[id]-query(1, id+1, n, 1)>a[id]) || rs[id] > a[id]) {
          ok=false;
          break;
        }
      }
    //  cout<<"i2="<<i<<endl;
      stk.push_back(id);
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
