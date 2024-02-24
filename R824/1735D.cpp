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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[M][23];
int main() {
  cin>>n>>k;
  vector<string> v;
  v.clear();
  map<string, int> cnt;
  cnt.clear();
  ll ans=0LL;
  for (int i = 1; i <= n; ++i) {
      string s="";
      for (int j =1; j <= k; ++j) {
          scanf("%d", &a[i][j]);
          s.push_back(a[i][j]+'0');
      }
      v.push_back(s);
  }
  for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
          string s="";
          for (int p = 0; p < k; ++p) {
              if (v[i][p]==v[j][p]) s.push_back(v[i][p]);
              else s.push_back(3-(v[i][p]-'0')-(v[j][p]-'0')+'0');
          }
          cnt[s]++;
      }
  }
  for (int i = 0; i < v.size(); ++i) {
      if (cnt.find(v[i]) != cnt.end()) {
          ll tmp = cnt[v[i]];
          ans += tmp*(tmp-1)/2LL;
      }
  }
  printf("%lld\n", ans);
  return 0;
}
