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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N], b[N];
struct node {
  int l, r;
  int mx, mn;
} tree[N<<2];
vector<int> ps[N];
void build(int id, int l, int r) {
  tree[id].l = l;
  tree[id].r = r;
  if (l == r) {
    tree[id].mx=a[l];
    tree[id].mn=b[l];
    return;
  }
  int mid=(l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  tree[id].mx = max(tree[id*2].mx, tree[id*2+1].mx);
  tree[id].mn = min(tree[id*2].mn, tree[id*2+1].mn);
}
pair<int,int> query(int id, int l, int r) {
  if (l == tree[id].l && r == tree[id].r) {
    return make_pair(tree[id].mx, tree[id].mn);
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (r <= mid) {
    return query(id*2, l, r);
  } else if (l > mid) {
    return query(id*2+1, l, r);
  } else {
    auto pr1 = query(id*2, l, mid);
    auto pr2 = query(id*2+1, mid+1, r);
    return make_pair(max(pr1.first, pr2.first), min(pr1.second, pr2.second));
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      ps[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ps[a[i]].push_back(i);
    }
    bool ok=true;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      if (a[i] > b[i]) {
        ok=false;
        break;
      }
      if (a[i] != b[i]) {
        rk.push_back(make_pair(b[i], i));
      }
    }
  //  sort(rk.begin(), rk.end());
    build(1, 1, n);
    for (int i = 0; i < rk.size(); ++i) {
      int id = rk[i].second;
      int x = rk[i].first;
      if (ps[x].empty()) {
        ok=false;
        break;
      }
      int id2 = upper_bound(ps[x].begin(), ps[x].end(), id)-ps[x].begin();
      if (id2 < ps[x].size()) {
        if (id + 1 <= ps[x][id2]-1) {
          auto pr = query(1, id+1, ps[x][id2]-1);
          int mx = pr.first;
          int mn = pr.second;
          if (mx <= x && mn >= x) {
            continue;
          }
        } else {
          continue;
        }
      }
      id2--;
      if (id2 >= 0) {
        if (ps[x][id2]+1 <= id-1) {
          auto pr = query(1, ps[x][id2]+1, id-1);
          int mx = pr.first;
          int mn = pr.second;
          if (mx <= x && mn >= x) {
            continue;
          }
        } else {
          continue;
        }
      }
      ok=false;
      break;
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
