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
//ll a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int a,b,x,y;
    scanf("%d%d%d%d%d", &k, &a, &b, &x, &y);
    if (a < b) {
        swap(a,b);
        swap(x,y);
    }
    int res=0;
    if (y <= x) {
        if (k < b) res=0;
        else res = (k-b)/y+1;
    } else {
        if (k >= a) {
            int dt= (k-a)/x+1;
            res+=dt;
            k -= x*dt;
        }
        if (k >= b) {
            res += (k-b)/y+1;
        }
    }
    printf("%d\n", res);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
