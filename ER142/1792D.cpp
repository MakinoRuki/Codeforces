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
#define N 50005
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N][M];
struct node {
  int mx;
  node* nxt[11];
  node() {
    mx = 0;
    for (int i = 1; i <= 10; ++i) {
      nxt[i] = NULL;
    }
  }
};
node* root = NULL;
int idx[M];
void update(int id) {
  node* cur = root;
  for (int i = 1; i <= m; ++i) {
    idx[a[id][i]] = i;
  }
  for (int i = 1; i <= m; ++i) {
    if (!cur->nxt[idx[i]]) {
      cur->nxt[idx[i]] = new node();
    }
    cur=cur->nxt[idx[i]];
    cur->mx = max(cur->mx, i);
  }
}
int query(int id) {
  int ans=0;
  node* cur = root;
  for (int i = 1; i <= m; ++i) {
    if (!cur->nxt[a[id][i]]) {
      break;
    }
    cur=cur->nxt[a[id][i]];
    ans=max(ans, cur->mx);
  }
  return ans;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        scanf("%d", &a[i][j]);
      }
    }
    root = new node();
    for (int i = 1; i <= n; ++i) {
      update(i);
    }
    for (int i = 1; i <= n; ++i) {
      int ans = query(i);
      printf("%d", ans);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
