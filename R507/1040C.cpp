#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
ll t;
ll a[N];
int x[N];
ll b[N];
int main() {
  cin>>n>>t;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x[i]);
  }
  int maxv=x[1];
  bool ok = true;
  for (int i = 2; i <= n; ++i) {
    if (x[i] < maxv) {
      ok=false;
      break;
    }
    maxv=max(maxv, x[i]);
  }
  if (!ok) {
    cout<<"No"<<endl;
    return 0;
  }
  memset(b, -1, sizeof(b));
  int i = n;
  while(i >= 1) {
    if (x[i] != i) {
      // if (n==15) {
      //   cout<<"No1"<<endl;
      //   return 0;
      // }
      ok=false;
      break;
    }
    int j = i;
    while(j>=1 && x[j] == x[i]) {
      j--;
    }
    j++;
    for (int j2 = j; j2 < i; ++j2) {
      if (j2 == j) b[j2] = a[j2+1]+t;
      else b[j2] = max(b[j2-1]+1, a[j2+1]+t);
    }
    if (i < n) {
      b[i] = min(b[i+1]-1, a[i+1]+t-1);
    } else {
      b[i] = 3000000000000000000LL;
    }
    i = j-1;
  }
  if (b[1] < 0) b[1] = 1;
  
  for (int i = 2; i <= n; ++i) {
    // if (b[i] > 0) {
    //   if (b[i-1] >= b[i]) {
    //     // if (n==15) {
    //     //   cout<<"No2"<<endl;
    //     //   return 0;
    //     // }
    //     ok=false;
    //     break;
    //   }
    // } else {
    //   b[i] = b[i-1]+1;
    // }
    if (b[i] <= b[i-1]) {
      ok=false;
      break;
    }
  }
  // if (b[n] > 3000000000000000000LL) {
  //   ok=false;
  // }
  if (!ok) {
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  for (int i = 1; i <= n; ++i) {
    printf("%lld", b[i]);
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
