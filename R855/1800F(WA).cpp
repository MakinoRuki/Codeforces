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
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
map<pair<ll,int>, int> cnt[26];
int main() {
  cin>>n;
  for (int i = 0; i < 26; ++i) {
    cnt[i].clear();
  }
  for (int i = 0; i < n; ++i) {
    string s;
    cin>>s;
    int num[26]={0};
    for (int j = 0; j < s.size(); ++j) {
      num[s[j]-'a']++;
    }
    ll st = 0;
    for (int j = 0; j < 26; ++j) {
      if (num[j]%2) {
        st |= (1LL<<j);
      }
    }
    int sz = (int)s.size();
    sz %= 2;
    for (int j = 0; j < 26; ++j) {
      if (num[j] == 0) {
        cnt[j][make_pair(st, sz)]++;
      }
    }
  }
  ll ans = 0LL;
  for (int i = 0; i < 26; ++i) {
    auto mp = cnt[i];
    for (auto itr : mp) {
      auto pr = itr.first;
      ll x = pr.first;
      ll y = 0LL;
      for (int j = 0; j < 26; ++j) {
        if (j == i) continue;
        if ((1LL<<j) & x) continue;
        y |= (1LL<<j);
      }
      ans += (ll)itr.second * (ll)cnt[i][make_pair(y, 1-pr.second)];
    }
  }
  cout<<ans/2<<endl;
  return 0;
}
