#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
ll k;
ll x[N];
ll getgcd(ll a, ll b) {
  return b == 0 ? a : getgcd(b, a%b);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n>>k;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &x[i]);
    }
    sort(x+1, x+n+1);
    ll g = x[2]-x[1];
    for (int i =3; i <= n; ++i) {
      g = getgcd(g, x[i]-x[i-1]);
    }
    ll det = abs(x[n]-k);
    if (det % g == 0) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
//  set<int> ss;
//  ss.clear();
  // vector<int> vv;
  // vv.clear();
  // for (int i = 1; i <= n; ++i) {
  //   int x;
  //   scanf("%d", &x);
  // //  ss.insert(x);
  //   vv.push_back(x);
  // }
  // int cnt=0;
  // while(cnt<3) {
  //   cnt++;
  //   cout<<"cnt="<<cnt<<" "<<vv.size()<<endl;
  //   int sz=vv.size();
  //   for (int i = 0; i< sz; ++i) {
  //     for (int j = i+1; j< sz; ++j) {
  //       vv.push_back(2*vv[i]-vv[j]);
  //       vv.push_back(2*vv[j]-vv[i]);
  //     }
  //   }
  // }
  // set<int> ss(vv.begin(), vv.end());
  // vector<int> vv2(ss.begin(), ss.end());
  // for (int i = 0; i < vv2.size(); ++i) {
  //   cout<<i<<" "<<vv2[i]<<endl;
  // }
  return 0;
}
