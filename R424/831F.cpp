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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, h;
ll k;
int q, p;
int a[N];
ll sum;
bool check(ll d) {
  ll tot=0LL;
  for (int i = 1; i <= n; ++i) {
    tot += (a[i] + d - 1) / d * d;
  }
  return tot <= sum;
}
int main() {
  cin>>n>>k;
  sum = k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    //maxv=max(maxv, (ll)a[i]);
    sum += (ll)a[i];
  }
  ll d = 0;
  for (ll i = 1; i * i <= sum; ++i) {
    if (check(i)) d = max(d, i);
    if (check(sum/i)) d = max(d, sum/i);
  }
  cout<<d<<endl;
  return 0;
}
