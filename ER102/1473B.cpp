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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int q;
string s,t;
bool check(string& ss, int n, int g) {
  string tmp = ss.substr(0, g);
  for (int i = 0; i < n; i += g) {
    if (ss.substr(i, g) != tmp) {
      return false;
    }
  }
  return true;
}
int getgcd(int x, int y) {
  return y==0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>q;
  for (int cas=1; cas<=q; ++cas) {
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    int gcd = getgcd(n, m);
    if (check(s, n, gcd) && check(t, m, gcd) && s.substr(0, gcd) == t.substr(0, gcd)) {
      int lcm = n*m/gcd;
      string ans="";
      string tmp = s.substr(0, gcd);
      for (int i = 1; i <= lcm/gcd; ++i) {
        ans += tmp;
      }
      cout<<ans<<endl;
    } else {
      cout<<-1<<endl;
    }
  }
  return 0;
}
