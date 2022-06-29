#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#define N 500
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int main() {
  cin>>s;
  n = (int)s.size();
  ll tot = 0LL;
  ll sb = 0LL;
  for (int i = n-1; i >= 0; --i) {
    if (s[i] == 'a') {
      tot = (tot + sb) % mod;
      sb = sb * 2LL % mod;
    } else {
      sb = (sb + 1) % mod;
    }
  }
  cout<<tot<<endl;
  return 0;
}
