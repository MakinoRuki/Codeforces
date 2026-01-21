
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
#define M 10002
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
int nxt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n;
    int ans=0;
    int mx=0;
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
      mx=max(mx, a[i]);
      ans += mx;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = i+1; j <= n; ++j) {
        swap(a[i], a[j]);
        mx=0;
        int tmp=0;
        for (int k = 1; k <= n; ++k) {
          mx=max(mx, a[k]);
          tmp += mx;
        }
        ans=max(ans, tmp);
      }
    }
    cout<<ans<<endl;
  }

  

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
