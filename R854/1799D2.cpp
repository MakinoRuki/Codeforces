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
int cold[N];
int hot[N];
struct node {
  int l, r;
  ll mn;
  ll dt;
} tree[N<<2];
void pushdown(int id) {
  if (tree[id].dt > 0) {
    if (tree[id*2].mn < (1LL<<61)-1) {
      tree[id*2].dt += tree[id].dt;
    }
    if (tree[id*2+1].mn < (1LL<<61)-1) {
      tree[id*2+1].dt += tree[id].dt;
    }
    tree[id].dt = 0;
  }
}
void pushup(int id) {
  tree[id].mn = min(tree[id*2].mn+tree[id*2].dt, tree[id*2+1].mn+tree[id*2+1].dt);
}
void build(int id, int l, int r) {
  tree[id].l = l;
  tree[id].r = r;
  if (l == r) {
    tree[id].dt = 0LL;
    if (l == 1) {
      tree[id].mn = 0LL;
    } else {
      tree[id].mn = (1LL<<61)-1;
    }
    return;
  }
  int mid=(l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  tree[id].dt = 0;
  tree[id].mn = min(tree[id*2].mn, tree[id*2+1].mn);
}
ll query(int id, int l, int r) {
  if (tree[id].l == l && tree[id].r == r) {
    if (tree[id].mn >= (1LL<<61)-1) {
      tree[id].dt = 0;
    }
    return tree[id].mn+tree[id].dt;
  }
  int mid = (tree[id].l + tree[id].r)/2;
  pushdown(id);
  ll res = (1LL<<61)-1;
  if (r <= mid) {
    res =  query(id*2, l, r);
  } else if (l > mid) {
    res = query(id*2+1, l, r);
  } else {
    res =  min(query(id*2, l, mid), query(id*2+1, mid+1, r));
  }
  pushup(id);
  return res;
}
void update(int id, int pos, ll val) {
  if (tree[id].l == pos && tree[id].l == tree[id].r) {
    tree[id].mn += tree[id].dt;
    tree[id].dt = 0;
    tree[id].mn = min(tree[id].mn, val);
    return;
  }
  int mid = (tree[id].l + tree[id].r)/2;
  pushdown(id);
  if (pos <= mid) {
    update(id*2, pos, val);
  } else {
    update(id*2+1, pos, val);
  }
  pushup(id);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= k; ++i) {
      scanf("%d", &cold[i]);
    }
    for (int i = 1; i <= k; ++i) {
      scanf("%d", &hot[i]);
    }
    build(1, 1, k+1);
  //  cout<<"000"<<endl;
    for (int i = 1; i <= n; ++i) {
      //cout<<"i="<<i<<endl;
      ll vl = query(1, 1, a[i]);
      ll vi = query(1, a[i]+1, a[i]+1);
      ll vr = (1LL<<61)-1;
      if (a[i]+2 <= k+1) {
        vr = query(1, a[i]+2, k+1);
      }
     // cout<<"vvv="<<vl<<" "<<vi<<" "<<vr<<endl;
      ll res = (1LL<<61)-1;
      if (vl < (1LL<<61)-1) {
        res = min(res, vl + cold[a[i]]);
      }
      if (vi < (1LL<<61) -1) {
        res = min(res, vi + hot[a[i]]);
      }
      if (vr < (1LL<<61)-1) {
        res = min(res, vr + cold[a[i]]);
      }
      ll dt = (a[i] == a[i-1] ? hot[a[i]] : cold[a[i]]);
      // cout<<"dt="<<dt<<endl;
      // cout<<"res="<<res<<endl;
      tree[1].dt += dt;
      if (res < (1LL<<61)-1) {
        update(1, a[i-1]+1, res);
      }
      // for (int j = 1; j <= 7; ++j) {
      //   cout<<"j="<<j<<" "<<tree[j].l<<" "<<tree[j].r<<" "<<tree[j].mn<<" "<<tree[j].dt<<endl;
      // }
      //cout<<"i2="<<i<<endl;
    }
  //  cout<<tree[1].dt<<" "<<tree[1].mn<<endl;
    ll ans = query(1, 1, k+1);
    printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
 
