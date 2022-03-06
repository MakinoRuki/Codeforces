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
ll pw[20];
int getlen(int x) {
  int cnt=0;
  while(x) {
    cnt++;
    x/=10;
  }
  return cnt;
}
int main() {
  cin>>n>>k;
  pw[0] = 1 % k;
  for (int i = 1; i <= 10; ++i) {
    pw[i] = pw[i-1] * (ll)(10%k) % k;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  map<pair<int,int>, int> cnt;
  cnt.clear();
  ll tot = 0LL;
  for (int i = n; i >= 1; --i) {
    int len = getlen(a[i]);
    if (i == n) {
      cnt[make_pair(len, a[i]%k)]++;
    } else {
      for (int j = 1; j <= 10; ++j) {
        ll r1 = (ll)(a[i] % k) * (ll)(pw[j] % k) % k;
        ll r2 = (k-r1) % k;
        if (cnt.find(make_pair(j, r2)) != cnt.end()) {
          tot += cnt[make_pair(j, r2)];
        }
      }
      cnt[make_pair(len, a[i]%k)]++;
    }
    //cout<<i<<" "<<tot<<endl;
  }
  cnt.clear();
  for (int i = 1; i <=n; ++i) {
    int len = getlen(a[i]);
    if (i == 1) {
      cnt[make_pair(len, a[i]%k)]++;
    } else {
      for (int j = 1; j <= 10; ++j) {
        ll r1 = (ll)(a[i] % k) * (ll)(pw[j] % k) % k;
        ll r2 = (k-r1) % k;
        if (cnt.find(make_pair(j, r2)) != cnt.end()) {
          tot += cnt[make_pair(j, r2)];
        }
      }
      cnt[make_pair(len, a[i]%k)]++;
    }
    //cout<<i<<" "<<tot<<endl;
  }
  cout<<tot<<endl;
  return 0;
}
