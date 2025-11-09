
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
#define N 1000005
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
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        cnt[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    for (int i = 1; i <= n; ++i) {
        cnt[i] += cnt[i-1];
    }
    int ans=0;
    for (int g = 1; g <= n; ++g) {
        int res = cnt[min(n, 4*g-1)];
        if (3*g <= min(n, 4*g-1)) {
            res -= cnt[3*g]-cnt[3*g-1];
        }
        if (2*g <= min(n, 4*g-1)) {
            res -= cnt[2*g]-cnt[2*g-1];
        }
        if (g <= min(n, 4*g-1)) {
            res -= cnt[g]-cnt[g-1];
        }
        if (res <=k) ans=g;
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
