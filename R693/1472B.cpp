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
#define M 2000005
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
int t;
int w,h;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int an=0, bn=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i]==1) an++;
      else bn++;
    }
    if ((an+2*bn)%2) {
      cout<<"NO"<<endl;
    } else {
      bool ok=false;
      int c = (an+2*bn)/2;
      for (int x=0; x<=an; ++x) {
        int y = c-x;
        if (y >= 0 && y <= bn && (y%2==0)) {
          y /= 2;
          if (y >= 0 && y <= bn) {
            ok=true;
            break;
          }
        }
      }
      if (ok) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
  }
  return 0;
}
