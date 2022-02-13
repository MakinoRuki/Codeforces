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
#define M 500005
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
//int t;
string s;
int a[N];
int main() {
  cin>>n;
  for (int i =1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a+1, a+n+1);
  ll ans=0LL;
  int l = 1, r = n;
  while(l < r) {
    ans += (ll)(a[l]+a[r]) * (ll)(a[l]+a[r]);
    l++;
    r--;
  }
  cout<<ans<<endl;
  return 0;
}
