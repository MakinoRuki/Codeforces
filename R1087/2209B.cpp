
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
int a[N];
int p[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h;
 //   int p;
  //  int x,y;
    ll c,k;
    scanf("%d", &n);
  //  int ans=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
   // int ans=0;
    for (int i = 1; i <= n; ++i) {
      int cnt0=0,cnt1=0;
      for (int j = i+1; j <= n; ++j) {
        if (a[j] < a[i]) cnt0++;
        else if (a[j] > a[i]) cnt1++;
      }
      //ans = max(ans, max(cnt0, cnt1));
      printf("%d ", max(cnt0, cnt1));
    }
    cout<<endl;
   // printf("%d\n", ans);
  }
  return 0;
}

