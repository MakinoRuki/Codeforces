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
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int b[N];
int solve(int st) {
  vector<pair<int,int>> rk;
  rk.clear();
  set<int> ss;
  ss.clear();
  for (int i = st; i < n; i += 2) {
      rk.push_back(make_pair(a[i], i));
      ss.insert(i);
  }
  sort(rk.begin(), rk.end());
  int cur=n;
  for (int i = 0; i < rk.size(); ++i) {
      b[rk[i].second] = cur;
      cur--;
  }
  rk.clear();
  for (int i = 1; i <= n; ++i) {
      if (ss.find(i) == ss.end()) {
          rk.push_back(make_pair(a[i], i));
      }
  }
  sort(rk.begin(), rk.end());
  for (int i = 0; i < rk.size(); ++i) {
      b[rk[i].second] = cur;
      cur--;
  }
  int tot=0;
  for (int i = 2; i < n; ++i) {
      if (a[i]+b[i] > a[i-1]+b[i-1] && a[i]+b[i] > a[i+1]+b[i+1]) {
          tot++;
      }
  }
  return tot;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      scanf("%d", &n);
      for (int i = 1; i <= n; ++i) {
          scanf("%d", &a[i]);
      }
      int res1=solve(2);
      int res2=solve(3);
      if (res1 > res2) {
          solve(2);
      }
      for (int i = 1; i <= n; ++i) {
          printf("%d ", b[i]);
      }
      cout<<endl;
  }
// cin>>n;
//   for (int i = 1; i <= n; ++i) {
//       a[i]=i;
//   }
//   do {
//       int res1=solve(2);
//       int res2=solve(3);
//       cout<<max(res1, res2)<<endl;
//   } while(next_permutation(a+1, a+n+1));
  return 0;
}
