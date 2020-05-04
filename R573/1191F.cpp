#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
vector<pair<int, int>> xy;
map<int, int> xrk;
bool vis[N];
int BIT[N];
int id;
int lowbit(int x) {
  return x&(-x);
}
void update(int pos, int v) {
  while(pos <= id) {
    BIT[pos] += v;
    pos += lowbit(pos);
  }
}
int query(int pos) {
  int res=0;
  while(pos) {
    res += BIT[pos];
    pos -= lowbit(pos);
  }
  return res;
}
int main() {
  cin>>n;
  xy.clear();
  for (int i = 1; i <= n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    xy.push_back(make_pair(-y, x));
  }
  sort(xy.begin(), xy.end());
  vector<pair<int, int>> xs;
  xs.clear();
  for (int i = 0; i < n; ++i) {
    xs.push_back(make_pair(xy[i].second, i));
  }
  sort(xs.begin(), xs.end());
  id= 1;
  xrk.clear();
  for (int i = 0; i < n; ++i) {
    if (i>0 && xs[i].first != xs[i-1].first) {
      id++;
    }
    xrk[xs[i].first] = id;
  }
  ll ans=0LL;
  int i = 0;
  memset(BIT, 0, sizeof(BIT));
  memset(vis, false, sizeof(vis));
  while(i < xy.size()) {
    int j = 0;
    set<ll> ss;
    ss.clear();
    for (j = i; j < xy.size(); ++j) {
      if (xy[j].first == xy[i].first) {
        ss.insert(xy[j].second);
      } else {
        break;
      }
    }
    vector<int> sv(ss.begin(), ss.end());
    ll sum=0;
    for (int i = 0; i < sv.size(); ++i) {
      int id2 = xrk[sv[i]];
      if (!vis[id2]) {
        update(id2, 1);
        vis[id2] = true;
      }
    }
    for (int i = 0; i <sv.size(); ++i) {
      int id2 = xrk[sv[i]];
      int res1 = query(id2);
      int res2 = query(id);
      ans += (res1-sum)*(ll)(res2-res1+1);
      sum = res1;
    }
    i = j;
  }
  cout<<ans<<endl;
  return 0;
}
