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
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n, m;
int k[N];
int cnt[N];
bool check(vector<pair<int,int>>& sv, int tot, int ds) {
  map<int, int> mp;
  mp.clear();
  for (int i = 0; i < sv.size(); ++i) {
    int d = sv[i].first;
    int t = sv[i].second;
    if (d <= ds) {
      mp[t] = max(mp[t], d);
    }
  }
  int det=0;
  vector<pair<int, int>> rk;
  rk.clear();
  for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
    rk.push_back(make_pair(itr->second, itr->first));
  }
  // for (int i = 1; i <= n; ++i) {
  //   if (mp.find(i) == mp.end()) det += k[i];
  // }
  sort(rk.begin(), rk.end());
  int cur=0;
  int j = 0;
  for (int i = 1; i <= ds; ++i) {
    cur++;
    int sum=0;
    while(j < rk.size() && rk[j].first == i) {
      sum += k[rk[j].second];
      j++;
    }
    if (cur >= sum) {
      det += sum;
      cur -= sum;
    } else {
      det += cur;
      cur =0;
    }
    if (cur >= (tot-det)*2) {
      return true;
    }
  }
  return cur>=(tot-det)*2;
}
int main() {
  cin>>n>>m;
  int tot=0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &k[i]);
    tot += k[i];
  }
  set<pair<int,int>> ss;
  ss.clear();
  for (int i = 1; i <= m; ++i) {
    int d, t;
    scanf("%d%d", &d, &t);
    ss.insert(make_pair(d, t));
  }
  vector<pair<int,int>> sv(ss.begin(), ss.end());
  int l = 1, r = 2*tot;
  while(l<r) {
    int mid=(l+r)/2;
    if (check(sv, tot, mid)) {
      r = mid;
    } else {
      l = mid+1;
    }
  }
  cout<<r<<endl;
  return 0;
}
