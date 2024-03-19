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
#define N 300005
#define M 2005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      scanf("%d", &n);
      for (int i = 1; i <= n; ++i) {
          scanf("%d", &a[i]);
      }
      vector<pair<int,ll>> v;
      v.clear();
      ll tot=0LL;
      for (int i = 1; i <= n; ++i) {
          v.clear();
          ll sum=0LL;
          for (int j = i; j <= n; ++j) {
              ll cur=0LL;
              int mx=a[j];
              while(!v.empty() && a[j] < v.back().first) {
                  mx = max(mx, v.back().first);
                  sum -= v.back().second;
                  cur += v.back().second+1;
                  v.pop_back();
              }
              cur++;
              v.push_back(make_pair(mx, cur-1));
              sum += cur-1;
              tot += sum;
          }
      }
      printf("%lld\n", tot);
  }
  return 0;
}
