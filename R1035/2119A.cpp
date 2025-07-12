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
#define M 1002
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
//int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int a,b,x,y;
    scanf("%d%d%d%d", &a, &b, &x, &y);
    if (a>b) {
        if ((a^1)==b) {
            printf("%d\n", y);
        } else {
            puts("-1");
        }
    } else if (a==b) {
        puts("0");
    } else {
        if (x < y) {
            printf("%lld\n", (ll)(b-a)*(ll)x);
        } else {
            ll res = (ll)(b-a)/2*(ll)(x+y);
            if ((a%2)&&!(b%2)) {
                res += x;
            } else if (!(a%2) && (b%2)) {
                res += y;
            }
            printf("%lld\n", res);
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
