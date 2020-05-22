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
const ll mod = 1000000007LL;
int n;
int a[N], b[N];
int c[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  int i;
  for (i = 1; i <= n; ++i) {
    if (b[i] == 1) break;
  }
  int ans=2*n;
  if (i > n) {
    for (int j = n; j >= 1; --j) {
      if (j==n) c[j] = (b[j]==0 ? n+1 : b[j]-j);
      else c[j] = min((b[j]==0?n+1:b[j]-j), c[j+1]);
    }
    for (int j = 1; j <= n; ++j) {
      if (c[j] + (j-1) > 0) {
        ans = min(ans, j-1+n);
      }
    }
    cout<<ans<<endl;
  } else {
    int j;
    for (j = i; j <= n; ++j) {
      if (j-i != b[j]-1) break;
    }
   // cout<<"ok"<<endl;
    if (j > n) {
      int cnt=0;
      set<int> ss;
      ss.clear();
      for (int k = 1; k <= n; ++k) {
        ss.insert(a[k]);
      }
      int k;
      for (k = n-i+2; k <= n; ++k) {
     //   cout<<"k="<<k<<endl;
        if (ss.find(k) != ss.end()) {
          ss.erase(k);
          ss.insert(b[k-(n-i+1)]);
        } else {
          break;
        }
      }
      if (k > n) {
        cout<<i-1<<endl;
        return 0;
      }
    }
    ans = 2*n;
    for (int j = n; j >= 1; --j) {
      if (j==n) c[j] = (b[j]==0 ? n+1 : b[j]-j);
      else c[j] = min((b[j]==0?n+1:b[j]-j), c[j+1]);
    }
    for (int j = 1; j <= n; ++j) {
      if (c[j] + (j-1) > 0) {
        ans = min(ans, j-1+n);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
