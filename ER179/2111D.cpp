
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
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 500005
#define M 105
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int res[7][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    map<int,int> cnt;
    cnt.clear();
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]/100]++;
    }
    vector<pair<int,int>> v;
    v.clear();
    for (auto itr : cnt) {
      v.push_back(make_pair(itr.first, itr.second));
    }
    int l = 0, r = (int)v.size()-1;
    int cur=1;
    while(l < r) {
      if (cur>n) break;
      int dt = min(v[l].second, v[r].second);
    //  cout<<"dt="<<dt<<endl;
      for (int i = cur; i <= min(n, cur+dt-1); ++i) {
        res[1][i] = v[l].first;
        res[2][i] = v[r].first;
      }
      cur += dt;
      for (int i = cur; i <= min(n, cur+dt-1); ++i) {
        res[1][i] = v[r].first;
        res[2][i] = v[l].first;
      }
      cur += dt;
      v[l].second -= dt;
      if (v[l].second <= 0) l++;
      v[r].second -= dt;
      if (v[r].second <= 0) r--;
    }
    if (cur <= n) {
      for (int i = cur; i <= n; ++i) {
        res[1][i] = v[r].first;
        res[2][i] = v[r].first;
        // cout<<"i="<<i<<endl;
        // cout<<res[1][i]<<" "<<res[2][i]<<endl;
      }
    }
    // for (int j = 1; j <= 2; ++j) {
    //   for (int i = 1; i <= n; ++i) {
    //     cout<<"j="<<j<<" "<<"i="<<i<<" "<<res[j][i]<<endl;
    //   }
    // }
    for (int i = 3; i <= 6; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i&1) res[i][j] = res[1][j];
        else res[i][j] = res[2][j];
      }
    }
    map<int,set<int>> mp;
    mp.clear();
    for (int i =1; i <= m; ++i) {
      mp[a[i]/100].insert(a[i]);
    }
    for (int j = 1; j <= n; ++j) {
      int fl = res[1][j];
      auto x = *mp[fl].begin();
      res[1][j] = x;
      mp[fl].erase(x);
      if (mp[fl].empty()) mp.erase(fl);
    }
    mp.clear();
    for (int i =1; i <= m; ++i) {
      mp[a[i]/100].insert(a[i]);
    }
    for (int j = 1; j <= n; ++j) {
      int fl = res[2][j];
      auto x = *mp[fl].begin();
      res[2][j] = x;
      mp[fl].erase(x);
      if (mp[fl].empty()) mp.erase(fl);
    }
    for (int i = 3; i <= 6; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i&1) res[i][j] = res[1][j];
        else res[i][j] = res[2][j];
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d %d %d %d %d %d\n", res[1][i], res[2][i], res[3][i], res[4][i], res[5][i], res[6][i]);
    }
  }
  return 0;
}
