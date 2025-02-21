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
#define N 200005
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
int b[N];
ll sa[N], sb[N];
ll calc(int k, ll x) {
  return sa[x] + sb[k-x];
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &b[i]);
    }
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);
    // int kmx = 0;
    // int q1=n/3,r1=n%3;
    // int q2=m/3,r2=m%3;
    // kmx = min(q1,q2)*2;
    // if (min(r1,r2) == 1) {
    //   kmx++;
    // } else {
    //   if (max(r1,r2)>=4) kmx+=2;
    //   else kmx++;
    // } 
    sa[0]=0,sb[0]=0;
    int l=1,r=n;
    for (int i = 1; i <= n/2; ++i) {
      sa[i] = sa[i-1] + a[n+1-i]-a[i];
    }
    for (int i = 1; i <= m/2; ++i) {
      sb[i] = sb[i-1] + b[m+1-i]-b[i];
    }
    vector<ll> ans;
    ans.clear();
    // 三分板子
    // 如果第一条线段选i个，第二条选k-i，那么n-2i>=k-i&&m-2(k-i)>=i。
    for (int k = 1; 2*k-m<=n-k; ++k) {
      int l = max(0, 2*k-m);
      int r = min(k, n-k);
      if (l > r) break;
      while(r-l>3) {
        int m1=(2*l+r)/3, m2 = (l+2*r)/3;
        if (calc(k, m1) > calc(k, m2)) {
          r = m2;
        } else {
          l = m1;
        }
      }
      ll tmp=0LL;
      for (int i = l; i <= r; ++i) {
        tmp = max(tmp, calc(k, i));
      }
      ans.push_back(tmp);
    }
    printf("%d\n", (int)ans.size());
    for (auto x : ans) {
      printf("%lld ", x);
    }
    cout<<endl;
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
