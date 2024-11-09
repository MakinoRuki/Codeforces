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
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 500005
#define M 405
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, p;
int t;
int a[N];
void solve(int m, int l, int r, int f) {
  printf("%d\n", m);
  for (int i = 1; i <= m/2; ++i) {
    printf("%d ", i);
  }
  if (!f) printf("%d ", k);
  else printf("%d ", k-1);
  int st = k+1;
  if (f) st = k+2;
  for (int i = 1; i <= m/2; ++i) {
    printf("%d ", st);
    st++;
  }
  cout<<endl;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    if (k == (n+1)/2) {
      puts("1");
      puts("1");
      continue;
    }
    bool found=false;
    for (int m = 2; m <= n; ++m) {
      if (m%2) {
        int l = (k-1-m/2);
        int r = (n-k-m/2);
        if (l < 0 || r < 0) continue;
        if ((l%2) && (r%2)) {
          l--;
          r--;
          if (l>=0 && r>=0) {
            found=true;
            solve(m, l, r, 1);
            break;
          }
        } else if (!(l%2) && !(r%2)) {
          found=true;
          solve(m, l, r, 0);
          break;
        }
      }
    }
    if (!found) puts("-1");
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
