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
int n, m, k, q, p;
int l, r;
int t;
string s;
int mp[N];
int main() {
  cin>>q;
  vector<pair<int, pair<int,int>>> qs;
  qs.clear();
  for (int i = 1; i < N; ++i) {
    mp[i] = i;
  }
  for (int i = 1; i <= q; ++i) {
    int ty, x, y;
    scanf("%d", &ty);
    if (ty == 1) {
      scanf("%d", &x);
      qs.push_back(make_pair(1, make_pair(x, 0)));
    } else {
      scanf("%d%d", &x, &y);
      qs.push_back(make_pair(2, make_pair(x, y)));
    }
  }
  vector<int> ans;
  ans.clear();
  for (int i = qs.size()-1; i >= 0; --i) {
    if (qs[i].first == 2) {
      int x = qs[i].second.first;
      int y = qs[i].second.second;
      mp[x] = mp[y];
    } else {
      ans.push_back(mp[qs[i].second.first]);
    }
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d", ans[i]);
    if (i < ans.size()-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
