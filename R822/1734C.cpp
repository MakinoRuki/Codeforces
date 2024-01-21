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
#define N 1000005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    for (int i = 1; i <= n; ++i) {
      ans[i] = -1;
    }
    for (int i =1; i <= n; ++i) {
      if (s[i-1] == '1') {
        continue;
       //cout<<"i="<<i<<" "<<ans[i]<<endl;
      }
      for (int j = i; j <= n; j += i) {
        if (s[j-1] == '1') break;
        if (ans[j] < 0) ans[j] = i;
        //cout<<"j="<<i<<" "<<j<<" "<<ans[j]<<endl;
      }
    }
    ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
      if (s[i-1] == '0') {
      //  cout<<"i="<<i<<" "<<ans[i]<<endl;
        tot += ans[i];
      }
    }
    printf("%lld\n", tot);
  }
  return 0;
}
