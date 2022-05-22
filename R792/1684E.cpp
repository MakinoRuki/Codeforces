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
#define N 200005
#define M 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    map<int, int> mp;
    mp.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      mp[a[i]]++;
    }
    int tot=(int)mp.size();
    //ll ans = (1LL<<61)-1;
    int ans = tot;
    for (int i = 0; i <= n; ++i) {
      if (mp.find(i) == mp.end()) {
        ans -= i;
        break;
      }
    }
    //vector<int> v(ss.begin(), ss.end());
    vector<int> v;
    v.clear();
    for (auto itr : mp) {
      v.push_back(itr.first);
    }
    vector<pair<int,int>> rk;
    rk.clear();
    for (auto itr : mp) {
      rk.push_back(make_pair(itr.second, itr.first));
    }
    sort(rk.begin(), rk.end());
    // for (auto itr : mp) {
    //   v.push_back(make_pair(itr.first, itr.second));
    // }
    // for (int i = 1; i < v.size(); ++i) {
    //   v[i].second += v[i-1].second;
    // }
    int j = 0;
    int j2 = 0;
    int cnt=0;
    int sum=0;
    map<int, int> mp2;
    mp2.clear();
    for (int i = 0; i <= n; ++i) {
      if (mp.find(i) != mp.end() && mp[i]> k) {
        continue;
      }
      while(j < v.size() && v[j] < i) {
        if (mp2.find(v[j]) != mp2.end()) {
          sum -= mp2[v[j]];
          if (mp2[v[j]] == mp[v[j]]) {
            cnt--;
          }
          mp2.erase(v[j]);
        }
        j++;
      }
      if (i-j <= k) {
        int dt = i-j;
        if (mp.find(i) != mp.end()) {
          if (mp2.find(i) == mp2.end() || mp2[i] < mp[i]) {
            sum += mp[i]-mp2[i];
            mp2[i] = mp[i];
            cnt++;
          }
        }
        while(j2 < rk.size()) {
          if (sum >= dt) {
            break;
          }
          if (rk[j2].second <= i) {
            j2++;
            continue;
          }
          if (mp2.find(rk[j2].second) == mp2.end()) {
            int nd = min(dt-sum, rk[j2].first);
            sum += nd;
            mp2[rk[j2].second] = nd;
            if (nd == rk[j2].first) {
              cnt++;
              j2++;
            }
          } else {
            int nd = min(dt-sum, rk[j2].first-mp2[rk[j2].second]);
            sum += nd;
            mp2[rk[j2].second] += nd;
            if (mp2[rk[j2].second] == rk[j2].first) {
              cnt++;
              j2++;
            }
          }
        }
        ans = min(ans, tot + dt - cnt - i);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
