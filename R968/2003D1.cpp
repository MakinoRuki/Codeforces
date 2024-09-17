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
#define N 300005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    int mx=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &k);
      set<int> ss;
      ss.clear();
      for (int j = 1; j <= k; ++j) {
        int x;
        scanf("%d", &x);
        ss.insert(x);
      }
      vector<int> v(ss.begin(), ss.end());
      if (v[0] >= 2) {
        mx = max(mx, 1);
      } else if (v[0] == 1) {
        int j;
        for (j = 1; j < v.size(); ++j) {
          if (v[j] != v[j-1]+1) break;
        }
        mx=max(mx, v[j-1]+1);
      } else {
        int j;
        for (j = 1; j < v.size(); ++j) {
          if (v[j] != v[j-1]+1) break;
        }
        if (j >= v.size()) {
          mx=max(mx, v.back()+2);
        } else {
          if (v[j-1]+2<v[j]) {
            mx=max(mx, v[j-1]+2);
          } else {
            j++;
            for (;j<v.size(); ++j) {
              if (v[j] != v[j-1]+1) break;
            }
            mx=max(mx, v[j-1]+1);
          }
        }
      }
    }
    ll ans=0LL;
    if (mx <= m) {
      ans = (ll)(mx+1)*(ll)mx+(ll)(mx+1+m)*(ll)(m-mx)/2LL;
    } else {
      ans = (ll)(m+1)*(ll)mx;
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

