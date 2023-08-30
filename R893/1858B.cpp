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
#define N 100005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int s[N];
int main() {
  cin>>t;
  int d;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &s[i]);
    }
    int ans = 0;
    int sum=0;
    for (int i = 1; i <= m; ++i) {
      if (i == 1) {
        ans += (s[i]-1+d-1)/d;
      } else {
        ans += ((s[i]-s[i-1])+d-1)/d;
      }
    }
    ans += (n-s[m])/d+1;
    sum = ans;
   // cout<<"ans="<<ans<<endl;
    int cnt=0;
    for (int i = 1; i <= m; ++i) {
      int tmp=sum;
      if (i == 1) {
        tmp -= (s[i]-1+d-1)/d;
        tmp -= (s[i+1]-s[i]+d-1)/d;
        tmp += (s[i+1]-1+d-1)/d;
      } else if (i == m) {
        tmp -= (s[i]-s[i-1]+d-1)/d;
        tmp -= (n-s[i])/d+1;
        tmp += (n-s[i-1])/d+1;
      } else {
        tmp -= (s[i]-s[i-1]+d-1)/d;
        tmp -= (s[i+1]-s[i]+d-1)/d;
        tmp += (s[i+1]-s[i-1]+d-1)/d;
      }
      if (tmp < ans) {
        ans = tmp;
        cnt=1;
      } else if (tmp == ans) {
        cnt++;
      }
     // cout<<"i="<<i<<" "<<ans<<endl;
    }
    printf("%d %d\n", ans, cnt);
  }
  return 0;
}
