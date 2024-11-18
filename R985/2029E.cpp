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
#define M 405
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, p;
int t;
int a[N];
int pr[N];
int main() {
  memset(pr, 0, sizeof(pr));
  for (ll i = 2; i < N; ++i) {
    if (!pr[i]) {
      for (ll j = i*i; j < N; j += i) {
        if (!pr[j]) pr[j] = i;
      }
    }
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int p=0,cnt=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (!pr[a[i]]) {
        cnt++;
        p = a[i];
      }
    }
    if (cnt > 1) puts("-1");
    else if (cnt == 1) {
      bool ok=true;
      for (int i = 1; i <= n; ++i) {
        if (a[i] < p) {
          ok=false;
          break;
        }
        if (a[i] == p) continue;
        if ((a[i]%p)==0) continue;
        if ((a[i]%2)==0) {
          if (a[i]>=2*p) continue;
          ok=false;
          break;
        }
        if (2*p>a[i]-pr[a[i]]) {
          ok=false;
          break;
        }
      }
      if (ok) printf("%d\n", p);
      else puts("-1");
    } else {
      puts("2");
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

