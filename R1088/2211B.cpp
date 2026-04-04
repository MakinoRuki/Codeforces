
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
#define N 200005
#define M 110
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int b[N];
vector<string> v;
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // ll ans=1LL;
  // for (int i =1; i <= 500; ++i) {
  //   ans=ans*5813LL%9422LL;
  // }
  // cout<<ans<<endl;
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x,y;
    scanf("%d%d", &x, &y);
    if (x == y) {
      puts("1");
      for (int i = 1; i <= x; ++i) {
        printf("1 ");
      }
      for (int i = 1; i <= y; ++i) {
        printf("-1 ");
      }
      cout<<endl;
    } else {
      int dt = abs(x-y);
      ll sum=0;
      for (int i =1; i * i <= dt; ++i) {
        if ((dt%i)==0) {
          sum++;
          if (dt/i != i) sum++;
        }
      }
      sum %= mod3;
      printf("%lld\n", sum);
      // 如果不这样，会有case形如"1,1,1,-1,-1,-1,1,1,1"
      if (x > y) {
        for (int i = 1; i <= min(x, y); ++i) {
          printf("-1 ");
        }
        for (int i = 1; i <= x; ++i) {
          printf("1 ");
        }
      } else {
        for (int i = 1; i <= min(x, y); ++i) {
          printf("1 ");
        }
        for (int i = 1; i <= y; ++i) {
          printf("-1 ");
        }
      }
      cout<<endl;
    }
  }
  return 0;
}

