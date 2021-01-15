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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
int t;
int w,h;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &w, &h, &n);
    int res=1;
    while(w%2==0) {
      res *= 2;
      w /= 2;
    }
    while(h%2==0) {
      res *= 2;
      h /= 2;
    }
    if (res>=n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
