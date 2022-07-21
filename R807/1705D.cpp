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
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
     scanf("%d", &n);
     string s1, s2;
     cin>>s1>>s2;
     vector<pair<int,pair<int,int>>> v1, v2;
     v1.clear();
     v2.clear();
     int b1 = -1, e1 = -1;
     for (int i = 0; i < n; ++i) {
        if (i == 0 || (s1[i] != s1[b1])) {
          if (b1>=0) v1.push_back(make_pair(s1[b1]-'0', make_pair(b1, e1)));
          b1 = i;
          e1 = i;
        } else {
          e1 = i;
        }
     }
     if (b1>=0) v1.push_back(make_pair(s1[b1]-'0', make_pair(b1,e1)));
     b1 = -1, e1 = -1;
     for (int i = 0; i < n; ++i) {
        if (i == 0 || (s2[i] != s2[b1])) {
          if (b1>=0) v2.push_back(make_pair(s2[b1]-'0', make_pair(b1, e1)));
          b1 = i;
          e1 = i;
        } else {
          e1 = i;
        }
     }
     if (b1>=0) v2.push_back(make_pair(s2[b1]-'0', make_pair(b1,e1)));
     bool ok = true;
     if (v1.size() != v2.size()) {
      ok=false;
     } else {
      for (int i = 0; i < v1.size(); ++i) {
        if (v1[i].first != v2[i].first) {
          ok=false;
          break;
        }
      }
     }
     if (!ok) {
      puts("-1");
      continue;
     }
     ll tot=0LL;
     for (int i = 0; i < v1.size(); ++i) {
        if (v2[i].second.first < v1[i].second.first || v2[i].second.second > v1[i].second.second) {
          int l1 = v1[i].second.first;
          int r1 = v1[i].second.second;
          int l2 = v2[i].second.first;
          int r2 = v2[i].second.second;
          tot += max(r1,r2)-min(l1,l2)-(r1-l1);
        }
     }
     printf("%lld\n", tot);
  }
  return 0;
}
