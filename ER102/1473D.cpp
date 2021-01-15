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
#define N 200010
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
string s;
int sum[N];
// int minv[N];
// int maxv[N];
struct node {
  int l, r;
  int minv, maxv;
} tree[N<<4];
void build(int id, int l, int r) {
  tree[id].l=l;
  tree[id].r=r;
  if (l == r) {
    tree[id].minv = sum[l];
    tree[id].maxv = sum[l];
    return ;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  tree[id].minv=min(tree[id*2].minv, tree[id*2+1].minv);
  tree[id].maxv=max(tree[id*2].maxv, tree[id*2+1].maxv);
}
int query(int id, int l, int r, int f) {
  if (tree[id].l==l && tree[id].r==r) {
    if (f) return tree[id].maxv;
    else return tree[id].minv;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (r<=mid) return query(id*2, l, r, f);
  else if (l > mid) return query(id*2+1, l, r, f);
  else {
    if (f) return max(query(id*2, l, mid, f), query(id*2+1, mid+1, r, f));
    else return min(query(id*2, l, mid, f), query(id*2+1, mid+1, r, f));
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    cin>>s;
    for (int i = 0; i <= n; ++i) {
      sum[i] = 0;
      //minv[i] = 0;
    }
    // int minv1=0;
    // int maxv1=0;
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i-1] + (s[i-1]=='+' ? 1 : -1);
      // minv1 = min(minv1, sum[i]);
      // maxv1 = max(maxv1, sum[i]);
      // minv[i] = minv1;
      // maxv[i] = maxv1;
    }
    build(1, 1, n);
    while(m-->0) {
      int l, r;
      scanf("%d%d", &l, &r);
      int det=sum[r] - sum[l-1];
      int minv1 = min(0, (l-1>=1 ? query(1, 1, l-1, 0) : 0));
      int maxv1 = max(0, (l-1>=1 ? query(1, 1, l-1, 1) : 0));
      int minv2 = (r+1<=n ? query(1, r+1, n, 0)-det : sum[l-1]);
      int maxv2 = (r+1<=n ? query(1, r+1, n, 1)-det : sum[l-1]);
      int minv=min(minv1, minv2);
      int maxv=max(maxv1, maxv2);
      printf("%d\n", maxv-minv+1);
    }
  }
  return 0;
}
