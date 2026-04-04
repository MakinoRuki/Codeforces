
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
#define M 10002
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
// int a[N];
// int b[N];
// int c[N];
ll getgcd(ll x, ll y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll a,b,c,m;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &m);
    ll ab = a/getgcd(a,b)*b;
    ll ac = a/getgcd(a,c)*c;
    ll bc = b/getgcd(b,c)*c;
    ll abc = ab/getgcd(ab, c) * c;
    ll wabc=m/abc;
    ll wab=m/ab-wabc;
    ll wbc=m/bc-wabc;
    ll wac=m/ac-wabc;
    ll wa = m/a-wab-wac-wabc;
    ll wb = m/b-wab-wbc-wabc;
    ll wc = m/c-wbc-wac-wabc;
  //  cout<<"vv="<<wa<<" "<<wb<<" "<<wc<<" "<<wab<<" "<<wac<<" "<<wbc<<" "<<wabc<<endl;
    ll aa = wa*6+wab*3+wac*3+wabc*2;
    ll bb = wb*6+wab*3+wbc*3+wabc*2;
    ll cc = wc*6+wac*3+wbc*3+wabc*2;
    printf("%lld %lld %lld\n", aa, bb, cc);
  }

  

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
