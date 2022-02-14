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
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    map<int,int> cnt;
    cnt.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      // a[i] = rand()%50+1;
      // cout<<a[i]<<" ";
      cnt[a[i]]++;
    }
  //  cout<<endl;
    set<pair<int,int>> ss;
    ss.clear();
    for (int i = 1; i <= m; ++i) {
      int x,y;
      scanf("%d%d", &x, &y);
      ss.insert(make_pair(x, y));
    }
    // ll ans2=0LL;
    // for (auto itr1 : cnt) {
    //   for (auto itr2 : cnt) {
    //     int x = itr1.first;
    //     int y = itr2.first;
    //     if (x == y) continue;
    //     if (ss.find(make_pair(min(x,y), max(x,y))) != ss.end()) {
    //       continue;
    //     }
    //     ans2 = max(ans2, (ll)(itr1.second+itr2.second) * (ll)(x+y));
    //   }
    // }
  //  cout<<"ans2="<<ans2<<endl;
    int sq = (int)sqrt(n);
    vector<pair<int,int>> v1;
    map<int, set<int>> mp;
    mp.clear();
    for (auto itr : cnt) {
      if (itr.second > sq) {
        v1.push_back(make_pair(itr.first, itr.second));
      } else {
        mp[itr.second].insert(itr.first);
      }
    }
    vector<pair<int, vector<int>>> v2;
    v2.clear();
    for (auto itr : mp) {
      vector<int> tmp;
      tmp.clear();
      v2.push_back(make_pair(itr.first, tmp));
      for (auto v : itr.second) {
        v2.back().second.push_back(v);
      }
    }
    // for (int i = 0; i < v1.size(); ++i) {
    //   cout<<"i="<<i<<" "<<v1[i].first<<" "<<v1[i].second<<endl;
    // }
    // for (int i = 0; i < v2.size(); ++i) {
    //   cout<<"i2="<<i<<" "<<v2[i].first<<" "<<v2[i].second.size()<<endl;
    //   for (int j = 0; j <v2[i].second.size(); ++j) {
    //     cout<<"j="<<j<<" "<<v2[i].second[j]<<endl;
    //   }
    // }
    ll ans = 0LL;
    for (int i = 0; i < v1.size(); ++i) {
      for (int j = i+1; j < v1.size(); ++j) {
        int x=min(v1[i].first, v1[j].first);
        int y = max(v1[i].first, v1[j].first);
        if (ss.find(make_pair(x,y)) == ss.end()) {
          ans = max(ans, ((ll)v1[i].first+(ll)v1[j].first) * ((ll)v1[i].second + (ll)v1[j].second));
        }
      }
    }
  //  cout<<"ans="<<ans<<endl;
    for (int i = 0; i < v2.size(); ++i) {
      for (int j1 = v2[i].second.size()-1; j1 >= 0; --j1) {
        for (int j2 = j1-1; j2 >= 0; --j2) {
          int x = min(v2[i].second[j2], v2[i].second[j1]);
          int y = max(v2[i].second[j2], v2[i].second[j1]);
          if (ss.find(make_pair(x, y)) == ss.end()) {
            ans = max(ans, ((ll)v2[i].first + (ll)v2[i].first) * ((ll)x+(ll)y));
           // found=true;
            break;
          }
        }
      }
      for (int j = i+1; j < v2.size(); ++j) {
        int j1 = v2[i].second.size()-1;
        bool found=false;
        while(j1 >= 0) {
          int j2 = v2[j].second.size()-1;
          while(j2 >= 0) {
            int x = min(v2[i].second[j1], v2[j].second[j2]);
            int y = max(v2[i].second[j1], v2[j].second[j2]);
            if (ss.find(make_pair(x, y)) == ss.end()) {
              ans = max(ans, ((ll)v2[i].first + (ll)v2[j].first) * ((ll)x + (ll)y));
              found=true;
              break;
            }
            j2--;
          }
        //  if (found) break;
          j1--;
        }
      }
    }
  //  cout<<"ans="<<ans<<endl;
    for (int i = 0; i < v1.size(); ++i) {
      for (int j = 0; j < v2.size(); ++j) {
        int j2 = v2[j].second.size()-1;
        bool found=false;
        while(j2 >= 0) {
          int x = min(v1[i].first, v2[j].second[j2]);
          int y = max(v1[i].first, v2[j].second[j2]);
          if (ss.find(make_pair(x,y)) == ss.end()) {
            ans = max(ans, ((ll)v1[i].second + (ll)v2[j].first) * ((ll)x + (ll)y));
            found=true;
            break;
          }
          j2--;
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
