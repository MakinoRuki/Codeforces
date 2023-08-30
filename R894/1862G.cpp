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
#define N 200005
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
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    map<int,int> mp;
    mp.clear();
    map<int,int> mp2;
    mp2.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      mp[a[i]]++;
    }
    ll sum=0LL, mx=0LL;
    vector<ll> v;
    v.clear();
    for (auto itr : mp) {
      v.push_back(itr.first);
    }
    for (int i = 1; i < v.size(); ++i) {
      mp2[v[i]-v[i-1]]++;
      mx = max(mx, v[i]-v[i-1]);
    }
    for (auto itr : mp2) {
      sum += (ll)itr.first * (ll)itr.second;
    }
    scanf("%d", &q);
    vector<ll> ans;
    ans.clear();
    while(q-->0) {
      int id, x;
      scanf("%d%d", &id, &x);
      mp[a[id]]--;
      if (mp[a[id]] == 0) {
        mp.erase(a[id]);
        if (!mp.empty()) {
          auto itr = mp.upper_bound(a[id]);
          if (itr == mp.end() && itr != mp.begin()) {
            auto itr2 = itr;
            itr2--;
            int dt = a[id]-itr2->first;
            mp2[dt]--;
            sum -=dt;
            if (mp2[dt] == 0) {
              mp2.erase(dt);
            }
          } else if (itr != mp.end() && itr == mp.begin()) {
            int dt = itr->first-a[id];
            mp2[dt]--;
            sum -=dt;
            if (mp2[dt] == 0) {
              mp2.erase(dt);
            }
          } else {
            auto itr2 = itr;
            itr2--;
            int dt1 = a[id]-itr2->first;
            int dt2 = itr->first-a[id];
            int dt = itr->first-itr2->first;
            mp2[dt1]--;
            sum-=dt1;
            if (mp2[dt1] == 0) {
              mp2.erase(dt1);
            }
            mp2[dt2]--;
            sum-=dt2;
            if (mp2[dt2] == 0) {
              mp2.erase(dt2);
            }
            sum += dt;
            mp2[dt]++;
          }
        }
      }
      a[id] = x;
      if (mp.find(a[id]) == mp.end()) {
        if (!mp.empty()) {
          auto itr = mp.upper_bound(a[id]);
          if (itr == mp.end() && itr != mp.begin()) {
            auto itr2 = itr;
            itr2--;
            int dt = a[id]-itr2->first;
            mp2[dt]++;
            sum+=dt;
          } else if (itr != mp.end() && itr == mp.begin()) {
            int dt = itr->first-a[id];
            sum+=dt;
            mp2[dt]++;
          } else {
            auto itr2 = itr;
            itr2--;
            int dt1 = a[id]-itr2->first;
            int dt2 = itr->first-a[id];
            int dt = itr->first-itr2->first;
            mp2[dt]--;
            sum-=dt;
            if (mp2[dt] == 0) {
              mp2.erase(dt);
            }
            sum+=dt1;
            mp2[dt1]++;
            sum+=dt2;
            mp2[dt2]++;
          }
        }
      }
      mp[a[id]]++;
      mx = (mp2.empty() ? 0 : (*mp2.rbegin()).first);
      ans.push_back(sum + mx + (*mp.begin()).first);
     // cout<<"q="<<q<<endl;
     //  for (auto itr : mp) {
     //    cout<<itr.first<<" "<<itr.second<<endl;
     //  }
     //  for (auto itr2 : mp2) {
     //    cout<<itr2.first<<" "<<itr2.second<<endl;
     //  }
    }
    for (int i = 0; i < ans.size(); ++i) {
      printf("%lld", ans[i]);
      if (i < ans.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
