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
const ll mod1 = 1000000007LL;
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
ll hs[N], pw[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
  // }
  string s;
  cin>>s;
  n = (int)s.size();
  string ab;
  cin>>ab;
  scanf("%d", &k);
  int cnt=0;
  set<ll> ss;
  ss.clear();
  int base = 13331;
  hs[0]=0;
  pw[0]=1;
  for (int i = 1; i <= n; ++i) {
    hs[i]= hs[i-1]*base+s[i-1]-'a'+1;
    pw[i]=pw[i-1]*base;
  }
  for (int i = 1; i <= n; ++i) {
    ll hsh1 = 0LL;
    ll hsh2 = 0LL;
    cnt=0;
    for (int j = i; j <= n; ++j) {
      if (ab[s[j-1]-'a'] == '0') cnt++;
      if (cnt > k) break;
      ll res=hs[j]-hs[i-1]*pw[j-i+1];

      // 自然溢出能过
      //hsh = hsh*base+s[j]-'a'+1;
      
      // 单模hash会WA，双模hash会TLE
      //hsh1 = ((__int128)hsh1*base1%mod1+s[j]-'a'+1)%mod1;
     // hsh2 = ((__int128)hsh2*base2%mod2+s[j]-'a'+1)%mod2;
      ss.insert(res);
    }
  }
  ll ans = (int)ss.size();
  cout<<ans<<endl;
  return 0;
}
 
