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
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
string s;
int a[N];
bool vis[N];
ll b[N];
int x[N], y[N], tm[N];
int par[N];
int mv[N];
int find(int x) {
  return x==par[x] ? x : par[x] = find(par[x]);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    map<int, vector<pair<int,int>>> mpx, mpy;
    mpx.clear();
    mpy.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d%d", &x[i], &y[i], &tm[i]);
      par[i] = i;
      mv[i] = tm[i];
      mpx[x[i]].push_back(make_pair(y[i], i));
      mpy[y[i]].push_back(make_pair(x[i], i));
    }
    for (auto& itr : mpx) {
      sort(itr.second.begin(), itr.second.end());
      for (int i = 1; i < itr.second.size(); ++i) {
        if (itr.second[i].first - itr.second[i-1].first <= k) {
          int u = itr.second[i].second;
          int v = itr.second[i-1].second;
          int pu= find(u);
          int pv=find(v);
          if (pu != pv) {
            par[pu] = pv;
            mv[pv] = min(mv[pv], mv[pu]);
          }
        }
      }
    }
    for (auto& itr : mpy) {
      sort(itr.second.begin(), itr.second.end());
      for (int i = 1; i < itr.second.size(); ++i) {
        if (itr.second[i].first - itr.second[i-1].first <= k) {
          int u = itr.second[i].second;
          int v = itr.second[i-1].second;
          int pu= find(u);
          int pv=find(v);
          if (pu != pv) {
            par[pu] = pv;
            mv[pv] = min(mv[pv], mv[pu]);
          }
        }
      }
    }
    // for (int i = 1; i <= n; ++i) {
    //   cout<<i<<" "<<find(i)<<" "<<mv[find(i)]<<endl;
    // }
    int l = 0, r = 1000000000;
    while(l < r) {
      int mid = (l+r)/2;
      int cnt=0;
     // cout<<"x="<<l<<" "<<r<<endl;
      for (int i = 1; i <= n; ++i) {
        par[i] = find(i);
        if (par[i] == i && mv[i] > mid) {
          cnt++;
        }
      }
      if (cnt <= mid+1) {
        r = mid;
      } else {
        l = mid+1;
      }
    }
    printf("%d\n", r);
  }
  return 0;
}
