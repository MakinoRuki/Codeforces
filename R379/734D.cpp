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
#define N 500005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
vector<pair<string, pair<int,int>>> cs;
map<int, vector<int>> mp[4];
bool check(vector<int>& v, int l, int r) {
  int id1 = lower_bound(v.begin(), v.end(), l) - v.begin();
  int id2 = upper_bound(v.begin(), v.end(), r) - v.begin();
  id2--;
  if (id1 <= id2 && id1 >= 0 && id1 < v.size() && id2 >= 0 && id2 < v.size()) {
    return false;
  }
  return true;
}
int main() {
  cin>>n;
  int x0, y0;
  cin>>x0>>y0;
  cs.clear();
  for (int i = 1; i <= n; ++i) {
    cin>>s;
    int x,y;
    scanf("%d%d", &x, &y);
    cs.push_back(make_pair(s, make_pair(x, y)));
  }
  for (int i = 0; i < cs.size(); ++i) {
    int x = cs[i].second.first;
    int y = cs[i].second.second;
    mp[0][x+y].push_back(x);
    mp[1][x-y].push_back(x);
    mp[2][x].push_back(y);
    mp[3][y].push_back(x);
  }
 // cout<<"x="<<mp[0][6].size()<<endl;
  for (int i = 0; i < 4; ++i) {
    for (auto& itr : mp[i]) {
      sort(itr.second.begin(), itr.second.end());
    }
  }
  bool found=false;
  for (int i = 0; i < cs.size(); ++i) {
    int x = cs[i].second.first;
    int y = cs[i].second.second;
    if (cs[i].first == "Q" || cs[i].first == "B") {
      if (x + y == x0 + y0) {
        // cout<<x<<" "<<y<<" "<<x0<<" "<<y0<<endl;
        // cout<<"sz="<<mp[0][x+y].size()<<endl;
        if (check(mp[0][x+y], min(x0,x) + 1, max(x0,x) - 1)) {
          found=true;
          break;
        }
      }
      if (x - y == x0 - y0) {
        if (check(mp[1][x-y], min(x0,x) + 1, max(x0,x) - 1)) {
          found=true;
          break;
        }
      }
    }
    if (cs[i].first == "Q" || cs[i].first == "R") {
      if (x == x0) {
        if (check(mp[2][x], min(y0,y) + 1, max(y0,y) - 1)) {
          found=true;
          break;
        }
      }
      if (y == y0) {
        if (check(mp[3][y], min(x0,x) + 1, max(x0,x) - 1)) {
          found=true;
          break;
        }
      }
    }
  }
  if (found) puts("YES");
  else puts("NO");
  return 0;
}
