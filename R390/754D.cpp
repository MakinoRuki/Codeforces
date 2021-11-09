#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 52
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, h;
int k;
int q;
int main() {
  cin>>n>>k;
  vector<pair<pair<int,int>, int>> sgs;
  sgs.clear();
  set<pair<int,int>> ss;
  ss.clear();
  for (int i = 1; i <= n; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    sgs.push_back(make_pair(make_pair(l, r), i));
  }
  sort(sgs.begin(), sgs.end());
  int mx = -1;
  int id = 0;
  for (int i = 1; i <= n; ++i) {
    while(!ss.empty() && (*ss.begin()).first < sgs[i-1].first.first) {
      ss.erase(ss.begin());
    }
    int id2 = sgs[i-1].second;
    ss.insert(make_pair(sgs[i-1].first.second, id2));
    while(ss.size() > k) {
      ss.erase(ss.begin());
    }
    if (ss.size() == k) {
      int det = (*ss.begin()).first - sgs[i-1].first.first +1;
      if (det > mx) {
        mx = det;
        id = i;
      }
    }
  }
  ss.clear();
  for (int i = 1; i <= n; ++i) {
    while(!ss.empty() && (*ss.begin()).first < sgs[i-1].first.first) {
      ss.erase(ss.begin());
    }
    ss.insert(make_pair(sgs[i-1].first.second, sgs[i-1].second));
    while(ss.size() > k) {
      ss.erase(ss.begin());
    }
    if (id == i) {
      break;
    }
  }
  vector<int> ans;
  ans.clear();
  for (auto itr : ss) {
    ans.push_back(itr.second);
  }
  if (mx >= 0) {
    printf("%d\n", mx);
    for (int i = 0; i< ans.size(); ++i) {
      printf("%d", ans[i]);
      if (i < ans.size()-1) cout<<" ";
      else cout<<endl;
    }
  } else {
    puts("0");
    for (int i = 1; i <= k; ++i) {
      printf("%d", i);
      if (i < k) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
