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
#define M 12
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int q;
bool mat[N];
bool ug[N];
int lg[N];
int col[N];
struct node {
  int l, r;
  int v;
} tree[N<<2];
void build(int id, int l, int r) {
  tree[id].l = l;
  tree[id].r = r;
  if (l == r) {
    tree[id].v = col[l-1]+1;
    return;
  }
  int mid=(l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  tree[id].v = max(tree[id*2].v, tree[id*2+1].v);
}
int query(int id, int l, int r) {
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
int main() {
  cin>>n>>m;
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < m; ++j) {
  //     int x=rand()%2;
  //     if (x==1) cout<<"X";
  //     else cout<<".";
  //   }
  //   cout<<endl;
  // }
  // cin>>q;
  // for (int i = 1; i <= q; ++i) {
  //   int u = rand()%m+1;
  //   int v = rand()%m+1;
  //   if (u > v) swap(u, v);
  //   printf("%d %d\n", u, v);
  // }
  memset(mat, false, sizeof(mat));
  for (int i = 0; i < n; ++i) {
    string s;
    cin>>s;
    for (int j = 0; j < m; ++j) {
      if (s[j] == 'X') mat[i*m+j] = true;
      lg[i*m+j] = inf;
    }
  }
  for (int j = 0; j < m; ++j) {
    col[j] = 0;
  }
  memset(ug, false, sizeof(ug));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      // if (mat[i*m+j]) continue;
      // // if (i == 0) ug[i*m+j] = true;
      // // if (i-1>=0 && ug[(i-1)*m+j]) {
      // //   ug[i*m+j] = true;
      // // }
      // // if (j-1>=0 && ug[i*m+j-1]) {
      // //   ug[i*m+j] = true;
      // // }
      // lg[i*m+j] = j;
      // if (i == 0) lg[i*m+j] = 0;
      // if (i-1>=0 && lg[(i-1)*m+j] < inf) {
      //   lg[i*m+j] = min(lg[i*m+j], lg[(i-1)*m+j]);
      // }
      // if (j-1>=0 && lg[i*m+j-1] < inf) {
      //   lg[i*m+j] = min(lg[i*m+j], lg[i*m+j-1]);
      // }
      if (i==0 || j==0) {
        lg[i*m+j] =0;
      } else {
        lg[i*m+j] =j;
        if (i-1>=0) lg[i*m+j] = min(lg[i*m+j], lg[(i-1)*m+j]);
        if (j-1>=0) lg[i*m+j] = min(lg[i*m+j], lg[i*m+j-1]);
        col[j]=max(col[j], lg[i*m+j]);
      }
      if (mat[i*m+j]) lg[i*m+j] = j+1;
    }
  }
  // for (int i = 0; i < n; ++i) {
  //   cout<<"i="<<i<<" "<<ug[i*m+0]<<endl;
  // }
  // for (int j = 0; j < m; ++j) {
  //   bool found=false;
  //   for (int i = 0; i < n; ++i) {
  //     if (mat[i*m+j]) continue;
  //     found=true;
  //     col[j] = max(col[j], lg[i*m+j]);
  //   }
  //   if (!found) col[j] = j;
  //  // cout<<j<<" "<<col[j]<<endl;
  // }
  cin>>q;
  build(1, 1, m);
  while(q-->0) {
    int l, r;
    scanf("%d%d", &l, &r);
    int res = query(1, l, r);
    if (res <= l) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
