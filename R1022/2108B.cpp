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
#define N 3000005
#define M 750
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
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
    int x;
    scanf("%d%d", &n, &x);
    int z = __builtin_popcount(x);
    if (x == 0) {
        if (n == 1) puts("-1");
        else if (n%2) {
            printf("%d\n", n+3);
        } else {
            printf("%d\n", n);
        }
        continue;
    }
    if (z >= n) {
        printf("%d\n", x);
    } else {
        int dt = n-z;
        if (dt % 2) {
            if (x >= 2) {
                printf("%d\n", x+dt+1);
            } else {
                printf("%d\n", x + dt + 3);
            }
        } else {
            printf("%d\n", x + dt);
        }
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
