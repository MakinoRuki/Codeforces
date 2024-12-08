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
#define N 200005
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
    int z,y,x;
    scanf("%d%d%d", &x, &y, &z);
    if (x+1 != z) {
        puts("-1");
        continue;
    }
    if (z==0) {
        puts("-1");
        continue;
    }
    int y1=y/z;
    int y2=y%z;
    int res=z;
    if (y2) {
        res=(z-y2);
      if (res%2) res=res/2+1;
      else res/=2;
      res += y2;
    }
    int ans=y1;
    if (y2) ans++;
    while(res>1) {
        ans++;
        if (res%2) res=res/2+1;
        else res/=2;
    }
    printf("%d\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

