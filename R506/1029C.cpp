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
#define N 200005
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
  map<int, int> mp;
  mp.clear();
  map<pair<int,int>, int> cnt;
  cnt.clear();
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    mp[l]++;
    mp[r]--;
    cnt[make_pair(l, r)]++;
  }
  vector<pair<int,int>> v;
  v.clear();
  for (auto itr : mp) {
    v.push_back(make_pair(itr.first, itr.second));
  }
  for (int i = 1; i < v.size(); ++i) {
    v[i].second += v[i-1].second;
  }
  int ans = 0;
  vector<pair<int,int>> sg;
  sg.clear();
  for (int i = 0; i < v.size()-1; ++i) {
    if (v[i].second == n-1) {
      sg.push_back(make_pair(v[i].first, v[i+1].first));
      int len = v[i+1].first - v[i].first;
      if (v[i+1].second == n && i + 2 < v.size()) {
        len += v[i+2].first - v[i+1].first;
      }
      ans=max(ans, len);
    } else if (v[i].second == n) {
      int len = v[i+1].first - v[i].first;
      if (v[i+1].second == n-1 && i + 2 < v.size()) {
        len += v[i+2].first - v[i+1].first;
      }
      ans=max(ans, len);
    }
  }
  for (int i = 1; i < sg.size(); ++i) {
    int l1 = sg[i-1].first, r1 = sg[i-1].second;
    int l2 = sg[i].first, r2 = sg[i].second;
    if (cnt.find(make_pair(r1, l2)) != cnt.end() && cnt[make_pair(r1, l2)] == 1) {
      ans = max(ans, r2 - l1);
    }
  }
  cout<<ans<<endl;
  return 0;
}
