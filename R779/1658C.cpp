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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int m, k, q;
int n;
int t;
int c;
int a[N];
int getgcd(int x, int y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1;cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int id = 0;
    for (int i =1; i <= n; ++i) {
      if (a[i] == 1) {
        id=  i;
        break;
      }
    }
    if (id <= 0) {
      puts("NO");
    } else {
      int m = n;
      for (int i = 1; i < id; ++i) {
        a[++m] = a[i];
      }
      bool ok = true;
      for (int i = id+1; i <= m; ++i) {
        if (a[i] < 2) {
          ok=false;
          break;
        }
        if (a[i] == a[i-1]) {
          continue;
        }
        if (a[i] > a[i-1] && a[i] - a[i-1] > 1) {
          ok=false;
          break;
        }
      }
      if (ok) puts("YES");
      else puts("NO");
    }
  }
  // cin>>n;
  // for (int i = 1; i <= n; ++i) {
  //   a[i] = i;
  // }
  // do {
  //   int g = a[1];
  //   for (int i = 2; i <= n; ++i) {
  //     g = getgcd(g, i * a[i]);
  //   }
  //   if (g > 1) {
  //     for (int i =1; i <= n; ++i) {
  //       cout<<a[i]<<" ";
  //     }
  //     cout<<endl;
  //   }
  // } while(next_permutation(a+1, a+n+1));
  return 0;
}
