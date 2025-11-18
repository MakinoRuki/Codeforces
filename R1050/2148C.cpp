
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    vector<pair<int,int>> ab;
    ab.clear();
    for (int i = 1; i <= n; ++i) {
      int x,y;
      scanf("%d%d", &x, &y);
      ab.push_back(make_pair(x, y));
    }
    int cur=0, tm=0;
    ll ans=0LL;
    for (int i = 1; i <= n; ++i) {
      int dt = ab[i-1].first-tm;
      if ((dt % 2) == (ab[i-1].second^cur)) {
        ans += dt;
      } else {
        ans += dt-1;
      }
      cur = ab[i-1].second;
      tm = ab[i-1].first;
    }
    ans += m-tm;
    printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
