#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <list>
#include <random>
#define N 400005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int b[N];
vector<int> ids[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i= 1; i <= n; ++i) {
      ids[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ids[a[i]].push_back(i);
    }
    vector<int> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      if (ids[i].size() > 0) {
        v.push_back(i);
      }
    }
    while(!v.empty()) {
      vector<pair<int,int>> tmp;
      tmp.clear();
      vector<int> v2;
      for (int i = 0; i < v.size(); ++i) {
        tmp.push_back(make_pair(v[i], ids[v[i]].back()));
        ids[v[i]].pop_back();
        if (!ids[v[i]].empty()) {
          v2.push_back(v[i]);
        }
      }
      for (int i = 0; i < tmp.size(); ++i) {
        b[tmp[i].second] = tmp[(i+1)%(int)tmp.size()].first;
      }
      v.clear();
      for (int i = 0; i <v2.size(); ++i) {
        v.push_back(v2[i]);
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d", b[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
