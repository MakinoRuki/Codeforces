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
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
//int a[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
    
  // }
  int a,b;
  cin>>a>>b;
  int ans=0;
  while(a <= b) {
    ans++;
    a *= 3;
    b *= 2;
  }
  cout<<ans<<endl;
  return 0;
}
