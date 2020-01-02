#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <deque>
#define N 200005
using namespace std;
typedef long long ll;
int n, m;
int x[N], l[N], r[N];
int main() {
  //ios_base::sync_with_stdio(0);
  //cin.tie(nullptr);
  // freopen("data.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    cin>>x[i];
  }
  sort(x+1, x+n+1);
  set<pair<int, pair<int, int>>> rk;
  rk.clear();
  for (int i = 1; i <= n; ++i) {
    l[i]= r[i] = x[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (i == 1) {
      rk.insert(make_pair(1, make_pair(1, -1)));
    } else {
      if (x[i]-1 > x[i-1]) {
        rk.insert(make_pair(1, make_pair(i, -1)));
        l[i]= x[i]-1;
      }
    }
  }
  for (int i = n; i >= 1; -- i) {
    if (i == n) {
      rk.insert(make_pair(1, make_pair(n, 1)));
    } else {
      if (x[i] + 1 < l[i+1]) {
        rk.insert(make_pair(1, make_pair(i, 1)));
        r[i] = x[i] + 1;
      }
    }
  }
  // for (auto v : rk) {
  //   cout<<v.first<<" "<<v.second.first<<" "<<v.second.second<<endl;
  // }
  vector<int> ans;
  ans.clear();
  ll tot=0;
  for (int i = 1; i <= m; ++i) {
    auto cur = *rk.begin();
    ll d = cur.first;
    int id = cur.second.first;
    int f = cur.second.second;
  //  cout<<d<<" "<<id<<" "<<f<<endl;
    tot += d;
    if (f> 0) ans.push_back(x[id]+d);
    else ans.push_back(x[id]-d);
    rk.erase(cur);
    if (f > 0) {
      if (id == n) rk.insert(make_pair(d+1, make_pair(n, 1)));
      else if (x[id]+d+1<l[id+1]) {
        rk.insert(make_pair(d+1, make_pair(id, 1)));
        r[id]++;
      }
    } else {
      if (id == 1) rk.insert(make_pair(d+1, make_pair(1, -1)));
      else if (x[id]-d-1 > r[id-1]) {
        rk.insert(make_pair(d+1, make_pair(id, -1)));
        l[id]--;
      }
    }
  }
  cout<<tot<<endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout<<ans[i];
    if (i < ans.size()-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
