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
#define N 3000005
#define M 1005
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
int k, w;
int t;
int a[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
  // }
  cin>>n;
  int ans=0;
  vector<int> v;
  v.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    while(!v.empty() && v.back() < a[i]) {
      v.pop_back();
    }
    if (!v.empty()) {
      ans = max(ans, v.back() ^ a[i]);
    }
    v.push_back(a[i]);
  }
  v.clear();
  for (int i = n; i >= 1; --i) {
    while(!v.empty() && v.back() < a[i]) {
      v.pop_back();
    }
    if (!v.empty()) {
      ans = max(ans, v.back() ^ a[i]);
    }
    v.push_back(a[i]);
  }
  cout<<ans<<endl;
  return 0;
}
 
