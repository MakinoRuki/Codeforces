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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
struct node {
  int l, r;
  int rmst;
} tree[N<<2];
void build(int id, int l, int r) {
  tree[id].l = l;
  tree[id].r = r;
  tree[id].rmst = n+1;
  if (l == r) {
    return ;
  }
  int mid = (l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
}
void update(int id, int x, int y) {
  if (tree[id].l == tree[id].r) {
    tree[id].rmst = min(tree[id].rmst, y);
    return ;
  }
  int mid = (tree[id].l + tree[id].r)/2;
  if (x <= mid) {
    update(id*2, x, y);
  } else {
    update(id*2+1, x, y);
  }
  tree[id].rmst = min(tree[id].rmst, y);
}
int query(int id, int l, int r) {
  if (tree[id].l == l && tree[id].r == r) {
    return tree[id].rmst;
  }
  int mid = (tree[id].l + tree[id].r) / 2;
  if (r <= mid) {
    return query(id*2, l, r);
  } else if (l > mid) {
    return query(id*2+1, l, r);
  } else {
    return min(query(id*2, l, mid), query(id*2+1, mid+1, r));
  }
}
int main() {
  cin>>n>>q;
  set<int> ss;
  ss.clear();
  for (int i = 1; i <= n; ++i) {
    ss.insert(i);
  }
  build(1, 1, n);
  while(q-->0) {
    int tp;
    scanf("%d", &tp);
    if (tp == 0) {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      if (x == 0) {
        auto itr1 = ss.lower_bound(l);
        auto itr2 = ss.upper_bound(r);
        while(itr1 != itr2) {
          ss.erase(itr1++);
        }
      } else {
        update(1, l, r);
      }
    } else {
      int x;
      scanf("%d", &x);
      if (ss.find(x) == ss.end()) {
        puts("NO");
      } else {
        int pre = x;
        auto itr = ss.lower_bound(x);
        if (itr != ss.begin()) {
          auto itr2 = itr;
          itr2--;
          pre = (*itr2)+1;
        } else {
          pre = 1;
        }
        int idx = query(1, pre, x);
        if (idx > n) {
          puts("N/A");
          continue;
        }
        itr++;
        if (itr == ss.end()) {
          puts("YES");
        } else {
          if (idx < (*itr)) {
            puts("YES");
          } else {
            puts("N/A");
          }
        }
      }
    }
  }
  return 0;
}
