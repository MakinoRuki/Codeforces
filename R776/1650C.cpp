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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
vector<pair<pair<int,int>,int>> pts;
ll mn1[N], mn2[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    pts.clear();
    for (int i = 0; i < m; ++i) {
      int x, w;
      scanf("%d%d", &x, &w);
      pts.push_back(make_pair(make_pair(x, w), i));
    }
    sort(pts.begin(), pts.end());
    set<pair<int,int>> ss;
    ss.clear();
    ll tot=0LL;
    for (int i = 0; i < m; ++i) {
      ss.insert(make_pair(pts[i].first.second, i));
      tot += pts[i].first.second;
      if (ss.size() > n) {
        tot -= (*ss.rbegin()).first;
        ss.erase(--ss.end());
      }
      if (ss.size() == n) {
        mn1[i] = tot;
      }
    }
    tot = 0LL;
    ss.clear();
    for (int i = m-1; i >= 0; --i) {
      ss.insert(make_pair(pts[i].first.second, i));
      tot += pts[i].first.second;
      if (ss.size() > n) {
        tot -= (*ss.rbegin()).first;
        ss.erase(--ss.end());
      }
      if (ss.size() == n) {
        mn2[i] = tot;
      }
    }
    ll res = (1LL<<61)-1;
    int id = -1;
    for (int i = n-1; i <= m-1-n; ++i) {
      ll tmp = mn1[i] + mn2[i+1];
      if (id < 0 || res > tmp) {
        res = tmp;
        id = i;
      }
    }
    vector<pair<int,int>> lans, rans;
    lans.clear();
    rans.clear();
    ss.clear();
    for (int i = 0; i <= id; ++i) {
      ss.insert(make_pair(pts[i].first.second, i));
      if (ss.size() > n) {
        ss.erase(--ss.end());
      }
    }
    for (auto itr : ss) {
      lans.push_back(make_pair(pts[itr.second].first.first, pts[itr.second].second+1));
    }
    sort(lans.begin(), lans.end());
    ss.clear();
    for (int i = m-1; i > id; --i) {
      ss.insert(make_pair(pts[i].first.second, i));
      if (ss.size() > n) {
        ss.erase(--ss.end());
      }
    }
    for (auto itr : ss) {
      rans.push_back(make_pair(pts[itr.second].first.first, pts[itr.second].second+1));
    }
    sort(rans.begin(), rans.end());
    printf("%lld\n", res);
    for (int i = 0; i < lans.size(); ++i) {
      printf("%d %d\n", lans[i].second, rans[rans.size()-1-i].second);
    }
  }
  return 0;
}
