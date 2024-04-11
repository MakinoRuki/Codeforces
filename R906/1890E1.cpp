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
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
vector<pair<int,int>> sg[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i =1; i <= n; ++i) {
      sg[i].clear();
    }
    for (int i = 1; i <= m; ++i) {
      int l, r;
      scanf("%d%d", &l, &r);
      sg[l].push_back(make_pair(i, 1));
      sg[r].push_back(make_pair(i, -1));
    }
    int id0=-1,id1=-1;
    int ans=0;
    set<int> ss;
    ss.clear();
    map<pair<int,int>, vector<int>> mp;
    mp.clear();
    int n0=0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < sg[i].size(); ++j) {
        if (sg[i][j].second==1) {
          ss.insert(sg[i][j].first);
        }
      }
      int sz=(int)ss.size();
      if (sz == 0) {
        n0++;
      } else if (sz == 1) {
        int x=(*ss.begin());
        mp[make_pair(x, -1)].push_back(i);
      } else if (sz == 2) {
        int x=(*ss.begin());
        int y=(*ss.rbegin());
        mp[make_pair(x,y)].push_back(i);
      }
      for (int j = 0; j < sg[i].size(); ++j) {
        if (sg[i][j].second==-1) {
          ss.erase(sg[i][j].first);
        }
      }
    }
    int mx1=0,mx2=0;
    for (auto itr : mp) {
      int sz=(int)itr.second.size();
      if (itr.first.second<0) {
        
        if (sz>=mx1) {
          mx2=mx1;
          mx1=sz;
        } else if (sz>=mx2) {
          mx2=sz;
        }
      } else {
        int tmp=sz;
        int x=itr.first.first;
        int y=itr.first.second;
        if (mp.find(make_pair(x,-1)) != mp.end()) {
          tmp += (int)mp[make_pair(x,-1)].size();
        }
        if (mp.find(make_pair(y,-1)) != mp.end()) {
          tmp += (int)mp[make_pair(y,-1)].size();
        }
        ans=max(ans, tmp);
      }
    }
    ans=max(ans, mx1+mx2);
    printf("%d\n", ans+n0);
  }
  return 0;
}
