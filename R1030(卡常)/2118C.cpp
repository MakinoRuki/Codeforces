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
#define N 500005
#define M 1002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll k;
    scanf("%d%lld", &n, &k);
    ll ans=0LL;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 60; ++j) {
            if ((1LL<<j) & a[i]) {
                ans++;
                continue;
            }
            if ((1LL<<j) <= k) {
                pq.push(1LL<<j);
            }
        }
    }
    while(!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        if (k >= tp) {
            ans++;
            k -= tp;
        } else {
            break;
        }
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
