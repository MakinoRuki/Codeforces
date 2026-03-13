
#include <iostream>
#include <sstream>
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
#define N 2000005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
ll a[N];
ll ax, ay;
ll ans;
int x,y;
void calc(int x1, int y1) {
  if ((x1&y1) == 0) {
    if (abs(x-x1)+abs(y-y1) < ans) {
      ans = abs(x-x1)+abs(y-y1);
      ax = x1;
      ay = y1;
    }
  }
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // int x=123,y=321;
  // while(x) {
  //   cout<<x%2;
  //   x/=2;
  // }
  // cout<<endl;
  // while(y) {
  //   cout<<y%2;
  //   y/=2;
  // }
  // cout<<endl;
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h;
  //  int x,y;
    scanf("%d%d", &x, &y);
    ax=0,ay=0;
    ans=(1LL<<61)-1;
    calc(x, y);
    for (int i = 0; i <= 30; ++i) {
      int bx = ((1<<i)&x)>0;
      int by = ((1<<i)&y)>0;
      int bb = (1<<i)-1;
      if (bx && by) {
        calc(x, (y>>i<<i)-1 - (x&bb));
        calc((x<<i>>i)-1-(y&bb), y);
        calc((x>>i<<i)+(1<<i), y);
        calc(x, (y>>i<<i)+(1<<i));
      }
    }
    printf("%lld %lld\n", ax, ay);
  }
  return 0;
}

