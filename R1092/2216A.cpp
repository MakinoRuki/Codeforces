
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
#define N 500005
#define M 110
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
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
int b[N];
int p;
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // ll ans=1LL;
  // for (int i =1; i <= 500; ++i) {
  //   ans=ans*5813LL%9422LL;
  // }
  // cout<<ans<<endl;
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x, y;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++i) {
      scanf("%d", &a[i]);
    }
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      rk.push_back(make_pair(b[i], i));
    }
    sort(rk.begin(), rk.end());
    vector<int> ans;
    ans.clear();
    for (int i = (int)rk.size()-1; i >= 0; --i) {
      int dt = k+1-rk[i].first;
      for (int j = 1; j <= dt; ++j) {
        ans.push_back(rk[i].second);
      }
    }
    printf("%d\n", (int)ans.size());
    for (auto u : ans) {
      printf("%d ", u);
    }
    cout<<endl;
  }
  return 0;
}

