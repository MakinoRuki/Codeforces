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
#define N 200005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n,t,k;
int a[N];
int w[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    vector<int> as;
    as.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      as.push_back(a[i]);
    }
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i = 1; i <= k; ++i) {
      scanf("%d", &w[i]);
      rk.push_back(make_pair(w[i], i));
    }
    sort(rk.begin(), rk.end());
    sort(as.begin(), as.end());
    ll ans=0LL;
    for (int i = 0; i < rk.size(); ++i) {
      ans += as.back();
      if (rk[i].first==1) ans += as.back();
      as.pop_back();
      rk[i].first--;
    }
    reverse(as.begin(), as.end());
    for (int i = rk.size()-1; i>=0; --i) {
      int det=rk[i].first;
      if (det > 0) {
        ans += as.back();
      }
      for (int j = 1; j <= det; ++j) {
        as.pop_back();
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
