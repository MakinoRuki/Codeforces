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
#define N 200
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
string s;
int a[N];
int b[N];
bool vis[N];
int getgcd(int x, int y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d%d%d", &n, &m, &k);
    
  // }
  cin>>n;
  cin>>s;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
  }
  int lcm=a[1];
  for (int i = 2; i <= n; ++i) {
    int g = getgcd(lcm, a[i]);
    lcm = (lcm * a[i]) / g;
  }
  int ans = 0;
  for (int i = 0; i <= 12000; ++i) {
    int cnt=0;
    for (int j = 1; j <= n; ++j) {
      int q = (i-b[j]) / a[j] + 1;
      if (i < b[j]) q = 0;
      if (s[j-1] == '1' && (q%2==0)) {
        cnt++;
      } else if (s[j-1] == '0' && (q%2)) {
        cnt++;
      }
    }
    ans=max(ans, cnt);
  }
  cout<<ans<<endl;
  return 0;
}
