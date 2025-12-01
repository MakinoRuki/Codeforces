
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
int b[N];
ll ls[N][2], rs[N][2];
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
    int lid=-1,rid=-1;
    ll ans=-(1LL<<61)-1;
    ll sum=0LL;
    ls[0][0]=0LL;
    ls[0][1]=0;
    rs[n+1][0] = 0LL;
    rs[n+1][1] = n+1;
    int pre=1;
    ll ans2 = ans;
    for (int i = 1; i <= n; ++i) {
      if (sum + a[i] >= a[i]) {
        sum += a[i];
      } else {
        sum = a[i];
        pre=i;
      }
      ls[i][0] = sum;
      ls[i][1] = pre;
      ans2 = max(ans2, sum);
    }
    sum=0LL;
    pre=n;
    for (int i = n; i >= 1; --i) {
      if (sum + a[i] >= a[i]) {
        sum += a[i];
      } else {
        sum = a[i];
        pre=i;
      }
      rs[i][0] = sum;
      rs[i][1] = pre;
    }
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
      ll cur = a[i] + abs(b[i]);
   //   cout<<"i="<<i<<" "<<cur<<endl;
      if (cur > ans) {
        ans = cur;
        lid=i,rid=i;
        cnt=1;
      } else if (cur == ans) {
        cnt++;
      }
    //  cout<<"ans="<<ans<<endl;
      if (i-1>=1) {
        if (cur + ls[i-1][0] > ans) {
          ans = cur + ls[i-1][0];
          lid=ls[i-1][1];
          rid = i;
          cnt = 1;
        } else if (cur + ls[i-1][0] == ans) {
          cnt++;
        }
      }
   //   cout<<"ans="<<ans<<endl;
      if (i+1<=n) {
        if (cur + rs[i+1][0] > ans) {
          ans = cur + rs[i+1][0];
          rid=rs[i+1][1];
          lid = i;
          cnt = 1;
        } else if (cur + rs[i+1][0] == ans) {
          cnt++;
        }
      }
    //  cout<<"ans="<<ans<<endl;
      if (i-1>=1 && i+1<=n) {
        if (cur + rs[i+1][0] + ls[i-1][0] > ans) {
          ans = cur + rs[i+1][0] + ls[i-1][0];
          rid=rs[i+1][1];
          lid = ls[i-1][1];
          cnt = 1;
        } else if (cur + rs[i+1][0] + ls[i-1][0] == ans) {
          cnt++;
        }
      }
    //  cout<<"ans="<<ans<<endl;
    }
 //   cout<<ans<<" "<<cnt<<" "<<lid<<" "<<rid<<endl;
  //  cout<<ans<<" "<<ans2<<" "<<cnt<<endl;
    if ((k%2)==0) ans = min(ans, ans2);
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
