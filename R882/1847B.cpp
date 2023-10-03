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
#define N 200002
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int res=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (i==1) res=a[i];
      else res &= a[i];
    }
    if (res > 0) {
      puts("1");
    } else {
      int cnt=0;
      int cur=0;
      for (int i = 1; i <= n; ++i) {
        if (i == 1) {
          cur = a[i];
          cnt++;
        } else {
          if (cur == 0) {
            cur = a[i];
            cnt++;
          } else {
            cur &= a[i];
          }
        }
      }
      if (cur == 0) {
        printf("%d\n", cnt);
      } else {
        printf("%d\n", cnt-1);
      }
    }
  }
  return 0;
}
