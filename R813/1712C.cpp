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
#define N 200005
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int p[N];
int a[N];
int dp[N];
vector<int> ids[N];
// int p2[N];
// ll getgcd(ll x, ll y) {
//   return y == 0 ? x : getgcd(y, x%y);
// }
// ll getlcm(ll x, ll y) {
//   return x / getgcd(x, y) * y;
// }
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
  //  ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      dp[i] = 0;
      ids[i].clear();
    }
    dp[n+1] = 0;
    int mn = n+1;
    for (int i = n; i >= 1; --i) {
      dp[i] = dp[i+1];
      if (mn < a[i]) {
        dp[i] = 1;
      }
      mn = min(mn, a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      ids[a[i]].push_back(i);
    }
    // for (int  i = 1; i <= n; ++i) {
    //   cout<<"i="<<i<<" "<<dp[i]<<endl;
    // }
    int tot=0;
    int r = 0;
    for (int i = 1; i <= n; ++i) {
    //  cout<<"i1="<<i<<" "<<endl;
      if (a[i] == 0) {
        continue;
      }
      if (i <= r) {
        tot++;
        vector<int> tmp;
        tmp.clear();
        for (int j = 0; j < ids[a[i]].size(); ++j) {
          tmp.push_back(ids[a[i]][j]);
        }
        for (int j = 0; j < tmp.size(); ++j) {
          a[tmp[j]] = 0;
          r = max(r, tmp[j]);
        }
      } else {
        if (dp[i]) {
          tot++;
          vector<int> tmp;
          tmp.clear();
          for (int j = 0; j < ids[a[i]].size(); ++j) {
            tmp.push_back(ids[a[i]][j]);
          }
          for (int j = 0; j < tmp.size(); ++j) {
            a[tmp[j]] = 0;
            r = max(r, tmp[j]);
          }
        }
      }
     // cout<<"i2="<<i<<" "<<endl;
    }
    printf("%d\n", tot);
  }
  // cin>>n;
  // for (int i = 1; i <= n; ++i) {
  //   p[i] = i;
  // }
  // ll mx = 0LL;
  // do {
  //   ll tot=0LL;
  //   for (int i = 1; i <= n; ++i) {
  //     tot += getlcm(i, p[i]);
  //   }
  //   if (tot > mx) {
  //     mx = tot;
  //     for (int i = 1; i <= n; ++i) {
  //       p2[i] = p[i];
  //     }
  //   }
  // } while(next_permutation(p+1, p+n+1));
  // cout<<mx<<endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout<<p2[i]<<" ";
  // }
  // cout<<endl;
  return 0;
}
