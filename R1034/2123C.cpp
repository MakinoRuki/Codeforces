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
#define M 1002
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
bool res[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int j,k;
    scanf("%d", &n);
    for (int i =1 ; i <= n; ++i) {
      scanf("%d", &a[i]);
      res[i]=false;
    }
    int mn=inf;
    for (int i = 1; i <= n; ++i) {
      if (i > 1 && a[i] <= mn) {
        res[i]=true;
      }
      mn=min(mn, a[i]);
    }
    mn = 0;
    for (int i= n; i >= 1; --i) {
      if (i < n && a[i] >= mn) {
        res[i]=true;
      }
      mn = max(mn, a[i]);
    }
    res[1]=res[n]=1;
    for (int i =1 ; i <= n; ++i) {
      if (res[i]) printf("1");
      else printf("0");
    }
    cout<<endl;
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
