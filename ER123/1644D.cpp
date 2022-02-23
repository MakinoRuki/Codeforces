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
#define N 5005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
vector<pair<int,int>> qs;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d%d", &n, &m, &k, &q);
    qs.clear();
    for (int i = 0; i <q; ++i) {
      int x,y;
      scanf("%d%d", &x, &y);
     // x = rand()%n+1;
     // y = rand()%m+1;
     // cout<<x<<" "<<y<<endl;
      qs.push_back(make_pair(x, y));
    }
    set<int> rs, cs;
    rs.clear();
    cs.clear();
    ll tot=1LL;
    for (int i = q-1; i >= 0; --i) {
      int x = qs[i].first, y = qs[i].second;
      if (rs.find(x) == rs.end() && cs.size() < m) {
        tot = tot * (ll)k % mod2;
      } else if (cs.find(y) == cs.end() && rs.size() < n) {
        tot = tot * (ll)k % mod2;
      }
      rs.insert(qs[i].first);
      cs.insert(qs[i].second);
    }
    printf("%lld\n", tot);
  }
  return 0;
}
