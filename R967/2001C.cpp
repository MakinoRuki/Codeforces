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
#define N 300005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int par[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
      int cur=1;
      while(true) {
        printf("? %d %d\n", i, cur);
        fflush(stdout);
        int x;
        scanf("%d", &x);
        if (x == i) {
          par[i] = cur;
          break;
        }
        cur = x;
      }
    }
    printf("!");
    for (int i = 2; i <= n; ++i) {
      printf(" %d %d", i, par[i]);
    }
    cout<<endl;
    fflush(stdout);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
