#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#define N 200
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int x1=0,x2=0;
    int y1=0,y2=0;
    for (int i = 1; i <= n; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      if (x == 0) {
        y1 = min(y1, y);
        y2 = max(y2 ,y);
      } else {
        x1 = min(x1, x);
        x2 = max(x2, x);
      }
    }
  //  cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
    int res= 2 *  (x2-x1) + 2* (y2-y1);
    printf("%d\n", res);
  }
  return 0;
}
