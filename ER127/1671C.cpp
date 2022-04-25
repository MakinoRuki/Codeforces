#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <list>
#include <random>
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
ll sum[N];
ll res[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll x;
    scanf("%d%lld", &n, &x);
    sum[0] = 0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i-1] + (ll)a[i];
    }
    for (int i= 0; i <= n; ++i) {
      res[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      if (x >= sum[i]) {
        res[i] = (x-sum[i])/i+1;
      }
    }
    ll tot=0LL;
    for (int i = n; i >= 1; --i) {
      if(res[i] > 0) {
        tot += res[i];
      }
    }
    // int id = 0;
    // while(id + 1 <= n && sum[id+1] <= x) {
    //   id++;
    // }
    // if (id == 0) {
    //   puts("0");
    //   continue;
    // }
    // ll tot=0;
    // ll pre = 0LL;
    // while(id > 0) {
    //   ll det = (x - sum[id])/id+1 - pre;
    //  // cout<<id<<" "<<det<<endl;
    //   if (det <= 0) {
    //     break;
    //   }
    //   tot += det * (ll)id;
    //   pre += det;
    //   id--;
    // }
    printf("%lld\n", tot);
  }
  return 0;
}
