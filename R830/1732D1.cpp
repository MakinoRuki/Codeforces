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
ll xsum[N];
int main() {
  cin>>q;
  set<ll> ss;
  ss.clear();
  map<ll, ll> ans;
  ans.clear();
  ss.insert(0);
  while(q-->0) {
      string s;
      cin>>s;
      ll x;
      scanf("%lld", &x);
      if (s[0] == '+') {
          ss.insert(x);
      } else {
          ll cur=0;
          if (ans.find(x) != ans.end()) {
              cur = ans[x]/x;
          }
          while(ss.find(x * cur) != ss.end()) {
              cur++;
          }
          ans[x] = cur*x;
          printf("%lld\n", cur*x);
      }
  }
  return 0;
}
