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
int cnt[M];
int ans;
struct node {
  int l, r;
  int sum;
  int dt;
} tree[M<<2];
void pushdown(int id) {
  if (tree[id].dt != 0) {
    tree[id*2].dt += tree[id].dt;
    tree[id*2].sum += tree[id].dt * (tree[id*2].r-tree[id*2].l+1);
    tree[id*2+1].dt += tree[id].dt;
    tree[id*2+1].sum += tree[id].dt * (tree[id*2+1].r-tree[id*2+1].l+1);
    tree[id].dt = 0;
  }
}
void build(int id, int l, int r) {
  tree[id].l = l;
  tree[id].r = r;
  tree[id].sum = 0;
  tree[id].dt = 0;
  if (l == r) return;
  int mid=(l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
}
void update(int id, int l, int r, int v) {
  if (tree[id].l == l && tree[id].r == r) {
    tree[id].dt += v;
    tree[id].sum += v * (r-l+1);
    return;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  pushdown(id);
  if (r <= mid) {
    update(id*2, l, r, v);
  } else if (l >mid) {
    update(id*2+1, l, r, v);
  } else {
    update(id*2, l, mid, v);
    update(id*2+1, mid+1, r, v);
  }
  tree[id].sum = tree[id*2].sum + tree[id*2+1].sum;
}
int query(int id, int l, int r) {
  if (tree[id].l == l && tree[id].r == r) {
    return tree[id].sum;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  pushdown(id);
  if (r <= mid) {
    return query(id*2, l, r);
  } else if (l > mid) {
    return query(id*2+1, l, r);
  } else {
    return query(id*2, l, mid) + query(id*2+1, mid+1, r);
  }
}
int query1(int id, int l, int x, int pre) {
  if (tree[id].l == tree[id].r) {
    return tree[id].l;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  pushdown(id);
  if (l > mid) {
    return query1(id*2+1, l, x, pre - tree[id*2].sum);
  } else {
    int dt = tree[id*2].sum - pre;
    if (x == 1) {
      if (dt > 0) {
        return query1(id*2, l, x, pre);
      } else {
        return query1(id*2+1, mid+1, x, 0);
      }
    } else {
      if (dt < mid-l+1) {
        return query1(id*2, l, x, pre);
      } else {
        return query1(id*2+1, mid+1, x, 0);
      }
    }
  }
}
int query2(int id) {
  if (tree[id].l == tree[id].r) {
    return tree[id].l;
  }
  pushdown(id);
  if (tree[2*id+1].sum > 0) {
    return query2(2*id+1);
  }
  return query2(id*2);
}
int main() {
  cin>>n>>q;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  for (int i = 1; i <= 201000; ++i) {
    int num = cnt[i];
    cnt[i] = 0;
    int bt = 0;
    while(num) {
      if (num&1) {
      //  cout<<"v="<<i<<" "<<bt<<" "<<i+bt<<endl;
        cnt[i+bt]++;
      }
      num/=2;
      bt++;
    }
  }
  ans = 0;
  build(1, 1, 201000);
  for (int i = 1; i <= 201000; ++i) {
    if (cnt[i]) {
      //cout<<"i="<<i<<endl;
      update(1, i, i, 1);
    }
  }
 // cout<<"x="<<query2(1)<<endl;
  while(q-->0) {
    int k, m;
    scanf("%d%d", &k, &m);
    int n1 = a[k];
    int sum = (n1-1>= 1 ? query(1, 1, n1-1) : 0);
    
     int r = query1(1, n1, 1, sum);
   //  cout<<"r1="<<r<<endl;
    if (n1 <= r-1) {
      update(1, n1, r-1, 1);
    }
    update(1, r, r, -1);
 //   cout<<"???"<<endl;
    a[k] = m;
    sum = (m-1>=1 ? query(1, 1, m-1) : 0);
  //  cout<<"sum="<<sum<<endl;
    r = query1(1, m, 0, sum);
 //   cout<<"r2="<<r<<endl;
    if (m <= r-1) {
      update(1, m, r-1, -1);
    }
    update(1, r, r, 1);
    ans = query2(1);
    printf("%d\n", ans);
  }
  return 0;
}
