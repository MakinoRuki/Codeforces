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
int b[N];
ll sum[N];
ll xs[N];
int ln[N], rn[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    sum[0] = 0LL;
    xs[0] = 0;
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i]) b[++cnt] = i;
    }
    for (int i = 1; i <= cnt; ++i) {
      sum[i] = sum[i-1] + a[b[i]];
      xs[i] = xs[i-1] ^ a[b[i]];
    }
    for (int i = 1; i <= q; ++i) {
      int L, R;
      scanf("%d%d", &L, &R);
      // if (n >= 100000 && cas==1 && i == 2) {
      //   cout<<L<<" "<<ln[R]<<endl;
      //   continue;
      // }
      int lb = lower_bound(b+1, b+cnt+1, L)-b;
      int rb = upper_bound(b+1, b+cnt+1, R)-b-1;
      if (lb <= rb) {
        ll ans = sum[rb] - sum[lb-1] - (xs[rb]^xs[lb-1]);
       // cout<<"res="<<lb<<" "<<rb<<" "<<sum[rb]<<" "<<sum[lb-1]<<" "<<xs[rb]<<" "<<xs[lb-1]<<endl;
        int lid = lb, rid = rb;
        for (int l = lb; l <= min(rb, lb+33); ++l) {
          for (int r = rb; r >= max(l, rb-33); --r) {
          //  cout<<"lr="<<l<<" "<<r<<" "<<lid<<" "<<rid<<endl;
            //if (L == 3 && R == 6 && l == 4 && r == 6) cout<<"v="<<sum[r]<<" "<<sum[l-1]<<" "<<(xs[r]^xs[l-1])<<endl;
            if (sum[r] - sum[l-1] - (xs[r]^xs[l-1]) > ans || (sum[r] - sum[l-1] - (xs[r]^xs[l-1]) == ans && b[r]-b[l]+1<b[rid]-b[lid]+1)) {
              ans = sum[r] - sum[l-1] - (xs[r]^xs[l-1]);
              lid = l;
              rid = r;
            }
            //cout<<"lr2="<<lid<<" "<<rid<<endl;
          }
        }
        printf("%d %d\n", b[lid], b[rid]);
      } else {
        printf("%d %d\n", L, L);
      }
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
 
