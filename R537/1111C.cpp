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
#define N 100005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n,k;
ll a,b;
ll c[N];
struct node {
  int lev;
  int sum;
  int ls, rs;
} tree[N*30];
int cnt=0;
void update(int cur, int pw, int x) {
  tree[cur].lev = pw;
  tree[cur].sum++;
  if (pw == 0) return;
  int b = pw-1;
  if ((1<<b)&x) {
    if (tree[cur].rs < 0) {
      tree[cur].rs = ++cnt;
    }
    update(tree[cur].rs, pw-1, x);
  } else {
    if (tree[cur].ls < 0) {
      tree[cur].ls = ++cnt;
    }
    update(tree[cur].ls, pw-1, x);
  }
  // tree[cur].lev = pw;
  // if (pw == 0) {
  //   tree[cur].sum++;
  //   return ;
  // }
  // int b = pw-1;
  // if (!((1<<b)&x)) {
  //   if (tree[cur].ls < 0) {
  //     tree[cur].ls = ++cnt;
  //   }
  //   update(tree[cur].ls, pw-1, x);
  // } else {
  //   if (tree[cur].rs < 0) {
  //     tree[cur].rs = ++cnt;
  //   }
  //   update(tree[cur].rs, pw-1, x);
  // }
  // int tot=0;
  // if (tree[cur].ls >= 0) tot += tree[tree[cur].ls].sum;
  // if (tree[cur].rs >= 0) tot += tree[tree[cur].rs].sum;
  // tree[cur].sum = tot;
}
ll dfs(int cur) {
  if (tree[cur].sum == 0) {
    return a;
  }
  int pw = tree[cur].lev;
  ll res = b*(1LL<<pw)*tree[cur].sum;
  if (pw == 0) {
    return res;
  }
  ll res2 = 0LL;
  if (tree[cur].ls >= 0) {
    res2 += dfs(tree[cur].ls);
  } else {
    res2 += a;
  }
  if (tree[cur].rs >= 0) {
    res2 += dfs(tree[cur].rs);
  } else {
    res2 += a;
  }
  res = min(res, res2);
  //cout<<"cur="<<cur<<" "<<"res="<<res<<endl;
  return res;
}
int main() {
  cin>>n>>k>>a>>b;
  for (int i = 1; i <= k; ++i) {
    scanf("%lld", &c[i]);
  }
  for (int i = 0; i < 30*N; ++i) {
    tree[i].sum=0;
    tree[i].ls = -1;
    tree[i].rs = -1;
  }
  cnt=1;
  for (int i = 1; i <= k; ++i) {
    update(1, n, c[i]-1);
  }
//  cout<<"cnt="<<cnt<<endl;
  // for (int i = 1; i <= cnt; ++i) {
  //   cout<<"i="<<i<<endl;
  //   cout<<tree[i].lev<<" "<<tree[i].sum<<" "<<tree[i].ls<<" "<<tree[i].rs<<endl;
  // }
  ll ans = dfs(1);
  cout<<ans<<endl;
  return 0;
}
