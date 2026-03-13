
#include <iostream>
#include <sstream>
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
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int lb[N];
int calc(int l, int r) {
  int cnt=0;
  for (int i = l; i <= r; ++i) {
    if (i == l) cnt++;
    else {
      int id = lb[i];
      if (id == i) cnt++;
    }
  }
  return cnt;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h;
    int x,y;
    scanf("%d", &n);
    ll ans=0LL;
    vector<int> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      lb[i]=0;
      bool ok = true;
      int pre = -1;
      while(!v.empty() && a[i] <= a[v.back()]) {
        if (pre < 0) pre = lb[v.back()];
        else if (pre != lb[v.back()]) {
          ok=false;
        }
        v.pop_back();
      }
      if (!v.empty()) {
        if (ok) {
          if (pre < 0) {
            if (a[v.back()]+1 == a[i]) lb[i] = lb[v.back()];
            else lb[i] = i;
          } else {
            if (pre == lb[v.back()] && a[v.back()]+1 == a[i]) {
              lb[i] = lb[v.back()];
            } else {
              lb[i]=i;
            }
          }
        } else {
          lb[i] = i;
        }
      } else {
        lb[i] = i;
      }
      v.push_back(i);
    }
    ans = calc(1, n);
    // for (int i = 1; i <= n; ++i) {
    //   if (i == 1) {
    //     ans += n;
    //   } else {
    //     int id = lb[i];
    //     if (id == 0) {
    //       ans += (ll)i*(ll)(n-i+1);
    //     } else {
    //       if (a[i] == a[id]+1) {
    //         ans += (ll)(i-id) * (ll)(n-i+1);
    //       } else {
    //         ans += (ll)i*(ll)(n-i+1);
    //       }
    //     }
    //   }
    // }
    printf("%lld\n", ans);
  }
  return 0;
}

