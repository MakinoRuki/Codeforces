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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int par[N];
int cnt[N];
int a[N];
int tot;
int tot2;
set<pair<int,int>> ss;
int find(int x) {
  return x==par[x] ? x : par[x] = find(par[x]);
}
void merge(int id1, int id2) {
  int p1 = find(id1);
  int p2 = find(id2);
  if (p1 == p2) return;
  if (ss.find(make_pair(cnt[p1], p1)) != ss.end()) {
    ss.erase(make_pair(cnt[p1], p1));
  }
  if (ss.find(make_pair(cnt[p2], p2)) != ss.end()) {
    ss.erase(make_pair(cnt[p2], p2));
  }
  par[p1] = p2;
  cnt[p2] += cnt[p1];
  ss.insert(make_pair(cnt[p2], p2));
}
int main() {
  cin>>n;
  vector<pair<int,int>> rk;
  rk.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    rk.push_back(make_pair(a[i], i));
    par[i] = i;
    cnt[i] = 1;
  }
  ss.clear();
  sort(rk.begin(), rk.end());
  int mxsz = 0, mnsz = inf;
  int ans = 1, loc = 0;
  int i = 0;
  tot = n;
  tot2 = n;
  while(i < rk.size()) {
    int k = rk[i].first + 1;
    while(i < rk.size() && rk[i].first < k) {
      int id = rk[i].second;
      int lid = id-1;
      par[id] = find(id);
      if (par[id] == id) ss.insert(make_pair(cnt[par[id]], par[id]));
      if (lid >= 1 && a[lid] < k) {
        merge(lid, id);
      }
      int rid = id+1;
      if (rid <= n && a[rid] < k) {
        merge(rid, id);
      }
      i++;
    }
    if (ss.empty()) continue;
    int sz = (int)ss.size();
    mnsz = (*ss.begin()).first;
    mxsz = (*(--ss.end())).first;
    if (mxsz == mnsz) {
      if (sz > loc) {
        loc = sz;
        ans = k;
      } else if (sz == loc && k < ans) {
        ans = k;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
