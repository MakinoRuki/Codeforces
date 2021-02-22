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
vector<pair<int, pair<int,int>>> abh;
ll dp[N];
struct node {
  int l, r;
  ll v;
} tree[N<<2];
void build(int id, int l, int r) {
  tree[id].l = l;
  tree[id].r = r;
  if (l==r) {
    tree[id].v = abh[l-1].second.second;
    return ;
  }
  int mid=(l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  tree[id].v = max(tree[id*2].v, tree[id*2+1].v);
}
ll query(int id, int l, int r) {
  if (tree[id].l == l && tree[id].r == r) {
    return tree[id].v;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (r <= mid) return query(id*2, l, r);
  else if (l > mid) return query(id*2+1, l, r);
  else {
    return max(query(id*2, l, mid), query(id*2+1, mid+1, r));
  }
}
void update(int id, int p, ll v) {
  if (tree[id].l == tree[id].r) {
    tree[id].v = v;
    return;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (p<=mid) update(id*2, p, v);
  else if (p > mid) update(id*2+1, p, v);
  tree[id].v = max(tree[id*2].v, tree[id*2+1].v);
}
int main() {
  cin>>n;
  abh.clear();
  for (int i = 0; i < n; ++i) {
    int a,b,h;
    scanf("%d%d%d", &a, &b, &h);
    abh.push_back(make_pair(b, make_pair(a, h)));
  }
  sort(abh.begin(), abh.end());
  build(1, 1, n);
  ll ans = 0LL;
  for (int i = 1; i <= n; ++i) {
    int l = 1, r = i;
    while(l < r) {
      int mid=(l+r)/2;
      if (abh[mid-1].first <= abh[i-1].second.first) {
        l = mid+1;
      } else {
        r = mid;
      }
    }
    if (r == i) {
      dp[i] = abh[i-1].second.second;
    } else {
      ll pre = query(1, r, i-1);
      dp[i] = pre + (ll)abh[i-1].second.second;
    }
    update(1, i, dp[i]);
    ans = max(ans, dp[i]);
  }
  cout<<ans<<endl;
  return 0;
}
