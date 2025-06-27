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
#define M 505
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int s;
    scanf("%d%d", &n, &s);
    int ans=0;
    for (int i = 1; i <= n; ++i) {
        int dx,dy,x,y;
        scanf("%d%d%d%d", &dx, &dy, &x, &y);
        // if (x == y) {
        //     if (dx == dy) ans++; 
        // } else if ((x+y) == s) {
        //     if ((dx+dy) == 0) ans++;
        // }
        if ((x==y && dx == dy) || (x+y==s && dx+dy == 0)) {
            ans++;
        }
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
