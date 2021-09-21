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
int t, n;
string s;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    cin>>s;
    int ans=0;
    for (int i = 0; i < n; ++i) {
      if (i < n-1 && s[i] > '0') {
        ans += s[i]-'0'+1;
      } else if (i == n-1 && s[i] > '0') {
        ans += s[i]-'0';
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
