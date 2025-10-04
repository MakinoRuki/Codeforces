
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
#define M 5002
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
int cnt[N];
int sum[N];
int main() {
  // for (int i = 2; i <= 500; ++i) {
  //   printf("%d ", (200000+i-1)/i);
  // }
  // cout<<endl;
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll y;
    scanf("%d%lld", &n, &y);
    sum[0]=0,cnt[0]=0;
    for (int i = 1; i < 500010; ++i) {
      cnt[i]=0;
      sum[i]=0;
    }
    int mx=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
      mx=max(mx, a[i]);
    }
    if (mx == 1) {
      printf("%d\n", n);
      continue;
    }
    for (int i = 1; i < N; ++i) {
      sum[i]=sum[i-1]+cnt[i];
     // cout<<"ii="<<i<<" "<<cnt[i]<<" "<<sum[i]<<endl;
    }
  //  cout<<sum[40]<<" "<<sum[41]<<" "<<sum[44]<<endl;
  //  cout<<"xx"<<endl;
    ll ans=-((1LL<<61)-1);
    for (int x = 2; x <= mx; ++x) {
        int up = (mx+x-1)/x;
        ll cur=0LL;
        for (int i = 1; i <= up; ++i) {
            ll l = (ll)(i-1)*(ll)x+1, r = (ll)x * (ll)i;
            ll num = sum[r] - sum[l-1];
            ll dt = max(0LL, num-cnt[i]);
            cur += num*i-dt*y;
           // if (x == 4) cout<<"i="<<i<<" "<<l<<" "<<r<<" "<<sum[r]<<" "<<sum[l-1]<<" "<<num<<" "<<dt<<" "<<cur<<endl;
          //  if (x==3 && num>0) cout<<"cur="<<i<<" "<<l<<" "<<r<<" "<<cur<<endl;
           // if (cur > 31) cout<<"xi="<<x<<" "<<i<<" "<<cur<<endl;
        }
       // if (cur==0) cout<<"xi="<<x<<" "<<cur<<endl;
        ans=max(ans, cur);
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
