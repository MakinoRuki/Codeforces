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
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n;
int a[N];
int b[N];
int main() {
  cin>>n;
  ll ans=0LL;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  sort(b+1, b+n+1);
  int cnt=0;
  for (int i = 1; i <= n; ++i) {
    if (i==1) a[++cnt] = b[i];
    else if (b[i] != b[i-1]) a[++cnt] = b[i];
  }
  n = cnt;
  // for (int i = 1; i <= n; ++i) {
  //   cout<<a[i]<<" ";
  // }
  //cout<<endl;
  int l = 1, r = 1;
  //ll n1=0,n2=0,n3=0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] < 0) {
      while(l <= n && a[l] <= a[i]) l++;
      int ub = a[i]/2;
      if (a[i]%2!=0) ub--;
      while(r <= n && a[r] <= ub) r++;
      if (l <= r) {
        ans += r-l;
      }
    } else {
      break;
    }
  }
 // n1=ans;
  l=1, r=1;
  for (int i = n; i >= 1; --i) {
    if (a[i] < 0) {
      while(l <= n && a[l] < (-a[i]+1)/2) l++;
      while(r <= n && a[r] <= -2*a[i]) r++;
      if (l <= r) {
        ans += r-l;
      }
     // cout<<"i="<<i<<" "<<l<<" "<<r<<endl;
    }
  }
  //n2=ans-n1;
  l = 1, r=1;
  for (int i = 1; i <= n; ++i) {
    if (a[i] > 0) {
      while(l <= n && a[l] <= a[i]) l++;
      while(r <= n && a[r] <= 2*a[i]) r++;
      if (l <= r) ans += r-l;
    }
  }
 // n3 = ans-n2-n1;
  //cout<<n1<<" "<<n2<<" "<<n3<<endl;
  cout<<ans<<endl;
  return 0;
}
