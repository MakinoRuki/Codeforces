#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    string ans="";
    int tot=q;
    for (int i = n; i >= 1; --i) {
      if (tot == 0) {
        if (q - tot >= a[i]) {
          ans += "1";
        } else {
          ans += "0";
        }
      } else {
        if (q - tot + 1 < a[i]) {
          ans += "1";
          tot--;
        } else {
          if (q - tot >= a[i]) {
            ans += "1";
          } else {
            ans += "1";
            tot--;
          }
        }
      }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
  }
  return 0;
}
