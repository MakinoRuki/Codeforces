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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string ans="";
    if (n % 3 == 0) {
      for (int i = 1; i <= n/3; ++i) {
        ans += "21";
      }
    } else if (n % 3 == 1) {
      ans += "1";
      for (int i = 1; i <= n/3; ++i) {
        ans += "21";
      }
    } else {
      for (int i = 1; i <= n/3; ++i) {
        ans += "21";
      }
      ans += "2";
    }
    cout<<ans<<endl;
  }
  return 0;
}
