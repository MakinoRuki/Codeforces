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
#define M 52
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int q;
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
    
  // }
  cin>>n;
  if (n % 2 == 0) {
    printf("%d\n", n/2);
    for (int i = 1; i <= n/2; ++i) {
      printf("%d", 2);
      if (i < n/2) cout<<" ";
      else cout<<endl;
    }
  } else {
    printf("%d\n", (n-3)/2+1);
    printf("%d", 3);
    for (int i = 1; i <= (n-3)/2; ++i) {
      printf(" %d", 2);
    }
    cout<<endl;
  }
  return 0;
}
