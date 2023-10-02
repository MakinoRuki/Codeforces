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
#define N 200010
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    map<int, pair<int,int>> mp;
    mp.clear();
    for (int i = 1; i <= n; ++i) {
      int l, r,a,b;
      scanf("%d%d%d%d", &l, &r, &a, &b);
      if (mp.find(b) == mp.end()) {
        mp[b] = make_pair(l, r);
      } else {
        int l1=mp[b].first;
        int r1=mp[b].second;
        mp[b] = make_pair(min(l1, l), max(r1, r));
      }
    }
    vector<pair<int, pair<int,int>>> v;
    v.clear();
    for (auto itr : mp) {
      v.push_back(make_pair(itr.first, itr.second));
    }
    for (int i = v.size()-2; i >= 0; --i) {
      if (v[i].first >= v[i+1].second.first) {
        v[i].first = v[i+1].first;
        int l1=v[i].second.first;
        int r1=v[i].second.second;
        v[i].second = make_pair(min(l1, v[i+1].second.first), max(r1, v[i+1].second.second));
      } else {
        v[i].second.second = min(v[i].second.second, v[i+1].second.first-1);
      }
    }
    scanf("%d", &q);
    int sz = (int)v.size();
    while(q-->0) {
      int x;
      scanf("%d", &x);
      int l = 0, r = sz-1;
      while(l < r) {
        int mid=(l+r+1)/2;
        if (v[mid].second.first <= x) {
          l = mid;
        } else {
          r = mid-1;
        }
      }
      if (x >= v[r].second.first && x <= v[r].second.second) {
        printf("%d ", max(x, v[r].first));
      } else {
        printf("%d ", x);
      }
    }
    cout<<endl;
  }
  return 0;
}
