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
#include <stack>
#include <bitset>
#include <chrono>
#define N 300005
#define M 2010
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
ll a[M];
ll check(vector<ll>& v) {
    ll ans=0LL;
    for (int i = 0; i < v.size(); i += 2) {
        ans = max(ans, abs(v[i+1]-v[i]));
    }
    return ans;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      scanf("%d", &n);
      for (int i = 1; i <= n; ++i) {
          scanf("%lld", &a[i]);
      }
      if (n==1) {
          puts("1");
          continue;
      }
      ll ans = (1LL<<61)-1;
      if (n%2) {
          for (int i = 1; i <= n; ++i) {
              bool ok=false;
              if (a[i]>0) {
                  if (i==1 || (a[i]-1 != a[i-1])) {
                      ok=true;
                  }
              }
              if (a[i] < 1000000000000000000LL) {
                  if (i == n || (a[i]+1 != a[i+1])) {
                      ok=true;
                  }
              }
              if (ok) {
                  vector<ll> v;
                  v.clear();
                  for (int j = 1; j <= n; ++j) {
                      if (i!=j) v.push_back(a[j]);
                  }
                  ans =min(ans, check(v));
              }
          }
      } else {
          vector<ll> v;
          v.clear();
          for (int i = 1; i <= n; ++i) {
              v.push_back(a[i]);
          }
          ans = min(ans, check(v));
      }
      printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

