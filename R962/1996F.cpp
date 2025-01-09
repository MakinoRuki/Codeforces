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
#define M 1005
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
int a[N];
int b[N];
bool check(int x) {
    ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= x) {
            tot += (a[i]-x)/b[i]+1;
        }
    }
    return tot >= k;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
    }
    int l = 0, r = 1000000000;
    while(l < r) {
        int mid = (l+r+1)/2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid-1;
        }
    }
  //  cout<<"r="<<r<<endl;
    ll ans=0LL;
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
        ll num = min(a[i]/b[i]+1, (a[i]-r+b[i]-1)/b[i]);
        if (num > 0) {
            cnt += num;
            ans += num*(ll)a[i]-num*(num-1)/2LL*(ll)b[i];
        }
    }
    if (cnt < k) {
        cnt = k-cnt;
        ans += (ll)r * (ll)cnt;
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

