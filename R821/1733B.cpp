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
#include <random>
#include <ctime>
#define N 200000
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x,y;
    scanf("%d%d%d", &n, &x, &y);
    if (x > 0 && y > 0) {
      puts("-1");
      continue;
    }
    if (x == 0 && y == 0) {
      puts("-1");
      continue;
    }
    if (x > y) swap(x, y);
    if (((n-1)%y) == 0) {
      int cur = 1;
      int cnt=0;
      for (int i = 2; i <= n; ++i) {
        cnt++;
        if (cnt > y) {
          cnt = 1;
          cur = i;
        }
        printf("%d ", cur);
      }
      cout<<endl;
    } else {
      puts("-1");
    }
  }
  return 0;
}
