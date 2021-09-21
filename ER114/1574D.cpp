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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
vector<ll> a[M];
ll b[M];
struct node {
  map<int, node*> nxt;
  node() {
    nxt.clear();
  }
};
void update(node* root, vector<ll>& v) {
  for (int i = 0; i < v.size(); ++i) {
    if (root->nxt.find(v[i]) == root->nxt.end()) {
      root->nxt[v[i]] = new node();
    }
    root = root->nxt[v[i]];
  }
}
void query(node* root, int lv, ll sum, ll& ans, vector<int>& tv, vector<int>& ids) {
  auto mp = root->nxt;
  if (lv == n) {
    for (auto itr : mp) {
      int id = itr.first-1;
      if (id >= 1 && mp.find(id) == mp.end()) {
        tv.push_back(id);
        if (sum + a[lv][id-1] > ans) {
          ans = sum + a[lv][id-1];
          ids = tv;
        }
        tv.pop_back();
      }
    }
  } else {
    for (auto itr : mp) {
      int id = itr.first;
      tv.push_back(id);
      query(itr.second, lv+1, sum+a[lv][id-1], ans, tv, ids);
      tv.pop_back();
      if (id - 1 >= 1 && mp.find(id-1) == mp.end()) {
        tv.push_back(id-1);
        if (sum + a[lv][id-2] + b[lv+1] > ans) {
          ans = sum + a[lv][id-2] + b[lv+1];
          ids = tv;
        }
        tv.pop_back();
      }
    }
  }
  int sz = (int)a[lv].size();
  if (mp.find(sz) == mp.end()) {
    tv.push_back(sz);
    if (sum + a[lv][sz-1] + b[lv+1] > ans) {
      ans = sum + a[lv][sz-1] + b[lv+1];
      ids = tv;
    }
    tv.pop_back();
  }
}
int main() {
  cin>>n;
  node* root = new node();
  for (int i = 1; i <= n; ++i) {
    a[i].clear();
    int c;
    scanf("%d", &c);
    for (int j = 1; j <= c; ++j) {
      ll x;
      scanf("%lld", &x);
      a[i].push_back(x);
    }
  }
  b[n+2] = b[n+1] = 0LL;
  for (int i = n; i >= 1; --i) {
    b[i] = a[i].back();
    if (i < n) b[i] += b[i+1];
  }
  cin>>m;
  for (int i = 1; i <= m; ++i) {
    vector<ll> tmp;
    tmp.clear();
    for (int j = 1; j <= n; ++j) {
      ll x;
      scanf("%lld", &x);
      tmp.push_back(x);
    }
    update(root, tmp);
  }
  ll ans = 0LL;
  vector<int> ids;
  ids.clear();
  vector<int> tv;
  tv.clear();
  query(root, 1, 0, ans, tv, ids);
//  cout<<ids.size()<<" "<<ans<<endl;
  for (int i = 1; i <= n; ++i) {
    if (i - 1 < ids.size()) {
      printf("%d", ids[i-1]);
    } else {
      printf("%d", (int)a[i].size());
    }
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
