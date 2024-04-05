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
#include <list>
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
ll sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    sum[0]=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      sum[i] = sum[i-1] + (ll)a[i];
    }
    vector<int> ids;
    ids.clear();
    for (int i =1 ; i <= n; ++i) {
      if (a[i] == 0) {
        ids.push_back(i);
      }
    }
    ll dt=0LL;
    ll ans=0LL;
    if (!ids.empty()) {
      for (int i = 1; i < ids[0]; ++i) {
        if (sum[i] == 0) ans++;
      }
    } else {
      for (int i = 1; i <= n; ++i) {
        if (sum[i] == 0) ans++;
      }
    }
    for (int i = 0; i < ids.size(); ++i) {
      map<ll, int> cnt;
      cnt.clear();
      int r= n;
      if (i < ids.size()-1) r = ids[i+1]-1;
      int mx=0;
      ll pre=0LL;
      for (int j = ids[i]; j <= r; ++j) {
        cnt[sum[j]+dt]++;
        if (cnt[sum[j]+dt] > mx) {
          mx=cnt[sum[j]+dt];
          pre=sum[j]+dt;
        }
      }
      ans+=mx;
      dt -= pre;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
