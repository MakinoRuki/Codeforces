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
ll cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll m;
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      cnt[i] = 0LL;
      scanf("%d", &a[i]);
      rk.push_back(make_pair(-a[i], i));
    }
    sort(rk.begin(), rk.end());
    scanf("%lld", &m);
    set<int> ss;
    ss.clear();
    ss.insert(0);
    ss.insert(n+1);
    cnt[n] = n;
    for (int i = 0; i < rk.size(); ++i) {
      int len = -rk[i].first;
      int j = rk[i].second;
      auto itr = ss.lower_bound(j);
      itr--;
      int l = *itr;
      auto itr2 = ss.upper_bound(j);
      int r = *itr2;
     // cout<<"j="<<j<<" "<<l<<" "<<r<<endl;
      cnt[r-l-1] -= len;
      cnt[j-l-1] += len;
      cnt[r-j-1] += len;
      ss.insert(j);
    }
    ll num=0;
    ll m2 = m;
    for (int i = n; i >= 1; --i) {
     // cout<<"i="<<i<<" "<<cnt[i]<<endl;
      ll dt = min(cnt[i], m2/i);
      num += dt;
      m2 -= dt*i;
      if (m2 > 0 && m2 < i && cnt[i] > dt) {
        num++;
        break;
      }
    }
    printf("%lld\n", m-num);
  }
  return 0;
}
