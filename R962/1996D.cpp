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
#define N 300005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    int qr = (int)sqrt(n);
    ll ans =0LL;
    for (int x = 1; x <= qr; ++x) {
        for (int y = x; y <= qr; ++y) {
            int r1 = (n-x*y)/(x+y);
            int r2 = m-x-y;
            int r = min(r1, r2);
            if (r >= y) {
                if (x == y) {
                    ans++;
                    if (r > y) {
                        ans += 3LL * (r-y);
                    }
                } else {
                    ans += 3;
                    ans += 6LL * (r-y);
                }
            }
        }
    }
    printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

