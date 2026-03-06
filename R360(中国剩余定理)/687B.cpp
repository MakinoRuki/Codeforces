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
#define M 110
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int c[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
  // }
  cin>>n>>k;
  memset(c, 0, sizeof(c));
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    c[a[i]]++;
  }
  bool ok=true;
  // x%lcm(c1,c2,...,cn)=r ==> x=t*lcm+r
  // (t*lcm+r)%k唯一 ==> (t*lcm)%k=0 ==> lcm%k=0
  for (int i =2; i * i <= k; ++i) {
    if ((k%i) == 0) {
      int tmp=1;
      while((k%i)==0) {
        tmp *= i;
        k /= i;
      }
      int j;
      for (j = tmp; j < N; j += tmp) {
        if (c[j]) {
          break;
        }
      }
      if (j >= N) ok=false; 
    }
  }
  if (k > 1) {
    int j;
    for (j = k; j < N; j += k) {
      if (c[j]) {
        break;
      }
    }
    if (j >= N) ok=false; 
  }
  if (ok) puts("Yes");
  else puts("No");
  return 0;
}
 
