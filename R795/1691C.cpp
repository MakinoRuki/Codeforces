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
#define N 100005
#define M 3000000
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q, p;
int t;
int a[N];
string s;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    int cnt=0;
    cin>>s;
    int b = -1, e = -1;
    ll tot=0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        cnt++;
        if (b<0) b=i;
        e=i;
      }
    }
    for (int i = 0; i < n-1; ++i) {
      if (s[i]=='1' && s[i+1]=='1') tot+=11;
      else if (s[i]=='1' && s[i+1] == '0') tot+=10;
      else if (s[i]=='0' && s[i+1] == '1') tot++;
    }
    if (cnt == 0) {
      puts("0");
      continue;
    }
    if (cnt == 1) {
      if (n-1-e<=k) {
        puts("1");
      } else if (b <=k) {
        puts("10");
      } else {
        puts("11");
      }
      continue;
    }
    if (e != n-1 && n-1-e<=k) {
      tot -= 10;
      k -= (n-1-e);
    }
    if (b > 0 && b<=k) {
      tot -= 1;
    }
    printf("%lld\n", tot);
  }
  return 0;
}
