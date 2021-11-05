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
#define M 52
#define N 35005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, h;
int k;
int q;
int dp[M][N];
vector<int> ids[N];
int a[N];
struct node {
  int l, r;
  int mx;
  int cv;
} tree[N<<2];
// void update(int i1, int j1, int i2, int j2, int add, int nw) {
//   if (dp[i1][j1][0] < dp[i2][j2][0] + add) {
//     dp[i1][j1][0] = dp[i2][j2][0] + add;
//     dp[i1][j1][1] = (nw ? i1 : dp[i2][j2][1]);
//   } else if (dp[i1][j1][0] == dp[i2][j2][0] + add) {
//     dp[i1][j1][1] = (nw ? i1 : max(dp[i2][j2][1], dp[i1][j1][1]));
//   }
// }
void pushdown(int id) {
  int det = tree[id].cv;
  tree[id*2].cv += det;
  tree[id*2].mx += det;
  tree[id*2+1].cv += det;
  tree[id*2+1].mx += det;
  tree[id].cv = 0;
  tree[id].mx = max(tree[id*2].mx, tree[id*2+1].mx);
}
void build(int id, int lv, int l, int r) {
  tree[id].l = l;
  tree[id].r = r;
  if (l == r) {
    tree[id].mx = dp[lv][l];
    tree[id].cv = 0;
    return;
  }
  int mid=(l+r)/2;
  build(id*2, lv, l, mid);
  build(id*2+1, lv, mid+1, r);
  tree[id].mx = max(tree[id*2].mx, tree[id*2+1].mx);
  tree[id].cv = 0;
}
void update(int id, int l, int r) {
  if (tree[id].l == l && tree[id].r == r) {
    tree[id].cv++;
    tree[id].mx++;
    return;
  }
  pushdown(id);
  int mid=(tree[id].l+tree[id].r)/2;
  if (r <= mid) {
    update(id*2, l, r);
  } else if (l > mid) {
    update(id*2+1, l, r); 
  } else {
    update(id*2, l, mid);
    update(id*2+1, mid+1, r);
  }
  tree[id].mx = max(tree[id*2].mx, tree[id*2+1].mx);
}
int query(int id, int l, int r) {
  if (tree[id].l == l && tree[id].r == r) {
    return tree[id].mx;
  }
  pushdown(id);
  int mid=(tree[id].l+tree[id].r)/2;
  if (r <= mid) {
    return query(id*2,l, r);
  } else if (l > mid) {
    return query(id*2+1, l, r);
  } else {
    return max(query(id*2, l, mid), query(id*2+1, mid+1, r));
  }
}
int main() {
  cin>>n>>k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    ids[a[i]].push_back(i);
  }
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  set<int> ss;
  ss.clear();
  for (int i = 1; i <= n; ++i) {
    ss.insert(a[i]);
    dp[1][i] = (int)ss.size();
  }
  build(1, 1, 1, n);
  for (int i = 2; i <= k; ++i) {
    for (int j = i; j <= n; ++j) {
      int id = lower_bound(ids[a[j]].begin(), ids[a[j]].end(), j) - ids[a[j]].begin();
    //  cout<<i<<" "<<j<<endl;
      // if (id == 0) {
      //   dp[i][j+1] = max(dp[i][j+1], dp[i][j]+1);
      // //  cout<<"v1"<<i<<" "<<j<<endl;
      //   update(i, 1, j+1);
      // //  cout<<"v2"<<i<<" "<<j<<endl;
      //   if (i+1<=k) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
      // //  cout<<"v3"<<i<<" "<<j<<endl;
      // } else {
      //   id = ids[a[j+1]][id-1];
      // //  cout<<"id="<<id<<endl;
      //   int v1 = query(i,1,id,j);
      //   if (v1 >= 0) {
      //     dp[i][j+1] = max(dp[i][j+1], v1+1);
      //   }
      //   if (id-1 >= 1) {
      //     int v2 = query(i, 1, 1, id-1);
      //     if (v2 >= 0) {
      //       dp[i][j+1] = max(dp[i][j+1], v2);
      //     }
      //   }
      // //  cout<<"x1"<<i<<" "<<j<<endl;
      //   update(i, 1, j+1);
      // //  cout<<"x2"<<i<<" "<<j<<endl;
      //   if (i+1<=k) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
      // //  cout<<"x3"<<i<<" "<<j<<endl;
      // }
      if (id > 0) {
        update(1, max(i-1, ids[a[j]][id-1]), j-1);
      } else {
        update(1, i-1, j-1);
      }
      dp[i][j] = query(1, i-1, j-1);
    }
   // cout<<"i1"<<i<<endl;
    build(1, i, 1, n);
   // cout<<"i2"<<i<<endl;
  }
  // for (int i = 1; i <= k; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
  //   }
  // }
  // for (int i = 0; i <= n; ++i) {
  //   for (int j = 0; j <= k; ++j) {
  //     cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
  //   }
  // }
  printf("%d\n", dp[k][n]);
  return 0;
}
