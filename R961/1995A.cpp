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
#define N 500005
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    map<int,int> cnt;
    cnt.clear();
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        cnt[i+j]++;
      }
    }
    set<pair<int,int>> ss;
    ss.clear();
    for (auto itr : cnt) {
      ss.insert(make_pair(-itr.second, itr.first));
    }
    int ans=0;
    for (auto itr : ss) {
      int dt = abs(itr.first);
      if (k == 0) {
        break;
      }
      if (k >= dt) {
        ans++;
        k -= dt;
      } else {
        ans++;
        k = 0;
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
