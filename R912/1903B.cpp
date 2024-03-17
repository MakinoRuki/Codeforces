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
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[M][M];
int ans[M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        scanf("%d", &a[i][j]);
      }
    }
    for (int b = 29; b >= 0; --b) {
      for (int i = 1; i <= n; ++i) {
        ans[i] |= (1<<b);
      }
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          if (i==j) continue;
          if (a[i][j] & (1<<b)) {
            continue;
          }
        //  if (b==4) cout<<"x="<<i<<" "<<j<<" "<<a[i][j]<<" "<<(a[i][j] & (1<<b))<<endl;
          if ((ans[i] & (1<<b))>0) {
            ans[i] ^= (1<<b);
          }
          if ((ans[j] & (1<<b)) >0) {
            ans[j] ^= (1<<b);
          }
        }
      }
     // cout<<"b="<<b<<endl;
      // for (int i = 1; i <= n; ++i) {
      //   cout<<ans[i]<<" ";
      // }
      // cout<<endl;
    }
    bool ok=true;
    for (int i = 1; i <= n; ++i) {
      for (int j =1; j <= n; ++j) {
        if (i != j) {
          if ((ans[i]|ans[j])!=a[i][j]) {
            ok=false;
            break;
          }
        }
      }
    }
    if (!ok) puts("NO");
    else {
      puts("YES");
      for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
      }
      cout<<endl;
    }
  }
  return 0;
}
