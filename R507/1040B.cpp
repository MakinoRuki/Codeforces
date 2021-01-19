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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, k;
int main() {
  cin>>n>>k;
  if (n<=2*k+1) {
    cout<<1<<endl;
    cout<<(1+n)/2<<endl;
    return 0;
  }
  for (int i = 1; i <= k+1; ++i) {
    for (int j = n; j >= n-k; --j) {
      if (i+k < j-k) {
        int det=j-k-(i+k)-1;
        if (det%(2*k+1)==0) {
          int ans = det/(2*k+1);
          cout<<ans+2<<endl;
          cout<<i<<" ";
          for (int x = i+k+k+1; x < j-k; x += 2*k+1) {
            printf("%d ", x);
          }
          cout<<j<<endl;
          return 0;
        }
      }
    }
  }
  return 0;
}
