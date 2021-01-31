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
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int q;
ll n;
int main() {
  cin>>n>>q;
  for (int cas=1; cas<=q; ++cas) {
    ll x,y;
    scanf("%lld%lld",&x,&y);
    if ((x+y)%2==0) {
      ll det=0;
      //int x2=x-1;
      x--;
      if (x>0) {
        if (n%2) {
          if (x%2==0) {
            det = x/2*n;
          } else {
            det = x/2*n+(n+1)/2;
          }
        } else {
          if (x%2==0) det = x/2*n;
          else det = x/2*n+n/2;
        }
      }
      if ((x+1)%2==0) {
        det += y/2;
      } else {
        det += (y+1)/2;
      }
      printf("%lld\n", det);
    } else {
      ll det=0;
      x--;
      if (x>0) {
        if (n%2) {
          if (x%2==0) {
            det = x/2*n;
          } else {
            det = x/2*n+n/2;
          }
        } else {
          if (x%2==0) det = x/2*n;
          else det=x/2*n+n/2;
        }
      }
      if ((x+1)%2==0) {
        det += (y+1)/2;
      } else {
        det += y/2;
      }
      ll bd=((ll)n*(ll)n+1)/2;
      printf("%lld\n", bd+det);
    }
  }
  return 0;
}
