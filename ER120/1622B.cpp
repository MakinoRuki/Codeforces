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
#define N 400005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
int p[N];
int ans[N];
string s;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);
    }
    cin>>s;
    vector<pair<int,int>> rk1, rk0;
    rk1.clear();
    rk0.clear();
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        rk1.push_back(make_pair(p[i+1], i));
      } else {
        rk0.push_back(make_pair(p[i+1], i));
      }
    }
    sort(rk0.begin(), rk0.end());
    sort(rk1.begin(), rk1.end());
    for (int i = 1; i <= (int)rk0.size(); ++i) {
      ans[rk0[i-1].second] = i;
    }
    for (int i = 1; i <= (int)rk1.size(); ++i) {
      ans[rk1[i-1].second] = (int)rk0.size() + i;
    }
    for (int i = 0; i < n; ++i) {
      printf("%d", ans[i]);
      if (i < n-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
