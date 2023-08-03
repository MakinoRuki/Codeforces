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
#define N 200005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
struct node {
  vector<int> v;
  node* nxt[2];
  node() {
    v.clear();
    nxt[0] = NULL;
    nxt[1] = NULL;
  }
};
vector<int> query(node* root, int x) {
  int res=0;
  int res2=0;
  for (int i = k-1; i >= 0; --i) {
    int bt = ((1<<i) & x) > 0;
    if (root->nxt[bt] && root->nxt[bt]->v.size() > 0) {
      res |= (1<<i);
      if (!bt) res2 |= (1<<i);
      root = root->nxt[bt];
    } else {
      root = root->nxt[!bt];
    }
  }
  return {res, res2, root->v[0]};
}
void update(node* root, int id) {
  for (int i = k-1; i >= 0; --i) {
    int bt = ((1<<i)&a[id]) >0;
    if (!root->nxt[bt]) {
      root->nxt[bt] = new node();
    }
    root = root->nxt[bt];
    root->v.push_back(id);
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    node* root = new node();
    int ans=-1;
    int x =-1, id1=-1, id2=-1;
    for (int i = 1; i <= n; ++i) {
    //  cout<<"i="<<i<<endl;
      if (i > 1) {
        auto vv = query(root, a[i]);
        if (vv[0] > ans) {
          ans = vv[0];
          x = vv[1];
          id1 = i;
          id2 = vv[2];
        }
      }
   //   cout<<"i2="<<i<<endl;
      update(root, i);
      // cout<<"i3="<<i<<endl;
    }
  //  cout<<ans<<endl;
    printf("%d %d %d\n", id1, id2, x);
  }
  return 0;
}
