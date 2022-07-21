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
     int n, c, q;
     scanf("%d%d%d", &n, &c, &q);
     string s;
     cin>>s;
     vector<pair<pair<ll,ll>, pair<ll,ll>>> v;
     v.clear();
     v.push_back(make_pair(make_pair(1,n), make_pair(1, n)));
     ll cur = n;
     for (int i = 1; i <= c; ++i) {
        ll l, r;
        scanf("%lld%lld", &l, &r);
        v.push_back(make_pair(make_pair(l, r), make_pair(cur+1, cur+r-l+1)));
        cur += r-l+1;
     }
   //  cout<<"???="<<v.size()<<endl;
     vector<char> ans;
     ans.clear();
     for (int i = 1; i <= q; ++i) {
        ll id;
        scanf("%lld", &id);
        for (int j = v.size()-1; j >= 0; --j) {
          //cout<<"id="<<id<<" "<<j<<" "<<v[j].second.first<<" "<<v[j].second.second<<endl;
          if (id >= v[j].second.first && id <= v[j].second.second) {
            if (id >= 1 && id <= n) {
              ans.push_back(s[id-1]);
             // cout<<"id="<<id<<endl;
              break;
            }
            id = id - v[j].second.first + v[j].first.first;
          }
        }
     }
     for (int i = 0; i < ans.size(); ++i) {
        printf("%c\n", ans[i]);
     }
  }
  return 0;
}
