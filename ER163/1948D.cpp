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
int sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    n=(int)s.size();
    int ans=0;
    for (int i = 1; i <= n/2; ++i) {
      for (int j=1; j <= n+1; ++j) {
        sum[j]=0;
      }
      for (int j = 1; j <= n; ++j) {
        if (j+i<=n) {
          if (s[j-1] == s[j+i-1]) sum[j]=1;
          else {
            if (s[j-1] != '?' && s[j+i-1] != '?') {
              continue;
            }
            sum[j]=1;
          }
        }
      }
      for (int j = n; j >= 1; --j) {
        sum[j] += sum[j+1];
      }
      for (int j = 1; j <= n; ++j) {
        if (j+2*i-1<=n) {
          if (sum[j]-sum[j+i] == i) {
            ans=max(ans, i*2);
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
