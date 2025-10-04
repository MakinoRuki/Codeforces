
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
#define N 600005
#define M 305
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
ll sum[N][2];
ll ans[N];
ll sum2[N];
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int l, r;
    scanf("%d", &n);
    sum[1][0] = 0LL;
    sum[1][1] = 0LL;
    sum2[0]=0LL;
    for (int i = 1; i <= 2*n; ++i) {
      scanf("%d", &a[i]);
      ans[i]=0LL;
      sum2[i]= sum2[i-1]+a[i]-a[i-1];
    }
    for (int i = 2; i <= 2*n; ++i) {
      sum[i][0] = sum[i-1][0];
      sum[i][1] = sum[i-1][1];
      if (i&1) {
        sum[i][1] += a[i]-a[i-1];
      } else {
        sum[i][0] += a[i]-a[i-1];
      }
    }
  //  cout<<"v="<<sum[3][1]<<" "<<sum[2][1]<<endl;
    ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
      ll dt = a[i+1]-a[i];
      tot += dt * (ll)i;
      ans[i] += tot;
    }
 //   cout<<ans[1]<<" "<<ans[2]<<endl;
    tot = 0LL;
    for (int i = 1; i <= n; ++i) {
      ll dt = a[2*n-i+1]-a[2*n-i];
      if (i < n) tot += dt * (ll)i;
   //   cout<<"i="<<i<<" "<<tot<<endl;
      ans[i] += tot;
    }
  //  cout<<ans[1]<<" "<<ans[2]<<endl;
    for (int i = 1; i < n; ++i) {
      ll dt = sum2[2*n-i]-sum2[i+1];
      ans[i] += dt * (ll)(i-1);
      if (i&1) {
        ans[i] += sum[2*n-i][0] - sum[i+1][0];
      } else {
        ans[i] += sum[2*n-i][1] - sum[i+1][1];
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%lld ", ans[i]);
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
