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
string s;
int x,y;
int dx[N], dy[N];
bool check(int len) {
  for (int i = 1; i + len - 1<=n; ++i) {
    int tx = dx[i-1] + dx[n]-dx[i+len-1];
    tx = abs(tx- x);
    int ty = dy[i-1] + dy[n] - dy[i+len-1];
    ty = abs(ty-y);
    if (tx+ty <= len && (len-tx-ty)%2==0) {
      return true;
    }
  }
  return false;
}
int main() {
  cin>>n;
  cin>>s;
  cin>>x>>y;
  memset(dx, 0, sizeof(dx));
  memset(dy, 0, sizeof(dy));
  for (int i = 1; i <= n; ++i) {
    dx[i] = dx[i-1] + (s[i-1] == 'R' ? 1 : (s[i-1] == 'L' ? -1 : 0));
    dy[i] = dy[i-1] + (s[i-1] == 'U' ? 1 : (s[i-1] == 'D' ? -1 : 0));
  }
  int ans=-1;
  if (dx[n] == x && dy[n] == y) {
    cout<<0<<endl;
    return 0;
  }
  int l = 1, r = (n%2==0 ? n/2+1 : (n+1)/2);
  while(l<r) {
    int mid=(l+r)/2;
    if (check(mid*2)) {
      r=mid;
    } else {
      l=mid+1;
    }
  }
  if (r <= n/2) {
    ans = (ans < 0 ? r*2 : min(ans, r*2));
  }
  l = 1, r = (n%2==0 ? n+1 : n+2);
  r = r/2+1;
  while(l<r) {
    int mid=(l+r)/2;
    if (check(2*mid-1)) {
      r=mid;
    } else {
      l = mid+1;
    }
  }
  if (2*r-1<=n) {
    ans = (ans < 0 ? 2*r-1 : min(ans, 2*r-1));
  }
  cout<<ans<<endl;
  return 0;
}
