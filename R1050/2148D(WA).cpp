
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
    scanf("%d", &n);
    vector<int> v0, v1;
    v0.clear();
    v1.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i]%2) v1.push_back(a[i]);
      else v0.push_back(a[i]);
    }
    ll ans=0LL;
    if (!v1.empty()) {
      sort(v1.begin(), v1.end());
      for (int i = 0; i < v0.size(); ++i) {
        ans += v0[i];
      }
      int l=0,r=v1.size()-1;
      while(l < r) {
        ans += v1[r];
        l++;
        r--;
      }
      if (l == r) ans += v1[r];
      printf("%lld\n", ans);
    } else {
      puts("0");
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
