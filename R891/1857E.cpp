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
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
ll ls[N], rs[N], sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ls[0]=rs[0]=sum[0]=0;
    ls[n+1]=rs[n+1]=sum[n+1]=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    vector<pair<int,int>> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      v.push_back(make_pair(a[i], i));
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; ++i) {
      ll dt = (i > 1 ? v[i-1].first-v[i-2].first : 0);
      ls[i] = ls[i-1] + dt * (ll)(i-1) + 1;
    }
    for (int i = n; i >= 1; --i) {
      ll dt = (i < n ? v[i].first-v[i-1].first : 0);
      rs[i] = rs[i+1] + dt * (ll)(n-i);
      int id = v[i-1].second;
      sum[id] = ls[i] + rs[i];
      rs[i]++;
    }
    for (int i = 1; i <= n; ++i) {
      printf("%lld", sum[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
