
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
#define M 5002
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
int b[N];
int dp[200][200];
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    //scanf("%d%d", &n, &k);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    int r1=0,r2=0;
    int c11=0,c00=0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] == b[i]) {
        if (a[i] == 1) c11++;
        else if (a[i] == -1) c00++;
      } else {
        if (a[i] > b[i]) {
          r1 += a[i];
        } else {
          r2 += b[i];
        }
      }
    }
    if (r1 > r2) swap(r1, r2);
    int dt = r2-r1;
    dt = min(dt, c11);
    c11 -= dt;
    r1 += dt;
    if (c11) {
      r1 += c11/2;
      r2 += c11/2;
      if (c11&1) r2++;
    }
    dt = min(c00, r2-r1);
    r2 -= dt;
    c00 -= dt;
    if (c00 > 0) {
      r1 -= c00/2;
      r2 -= c00/2;
      if (c00&1) r1--;
    }
    printf("%d\n", r1);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
