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
int sx, sy, ex, ey;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll n,l,r,k;
    scanf("%lld%lld%lld%lld", &n, &l, &r, &k);
    if (n % 2) {
        printf("%lld\n", l);
    } else {
        if (n == 2) puts("-1");
        else {
            int bt=0;
            while((1LL<<bt) <= l) {
                bt++;
            }
            if ((1LL<<bt) > r) {
                puts("-1");
            } else {
                if (k == n || k == n-1) {
                    printf("%lld\n", (1LL<<bt));
                } else {
                    printf("%lld\n", l);
                }
            }
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
