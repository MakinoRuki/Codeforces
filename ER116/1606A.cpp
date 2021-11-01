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
int t, n, m, h;
ll k;
int q;
string s;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>s;
    n = (int)s.size();
    int c1=0, c2=0;
    for (int i = 1; i < n; ++i) {
      if (s[i-1] == 'a' && s[i] == 'b') {
        c1++;
      } else if (s[i-1] == 'b' && s[i] == 'a') {
        c2++;
      }
    }
    if (c1 == c2) {
      cout<<s<<endl;
    } else {
      // c1 = 1, c2 = 1;
      // int i;
      // for (i = 1; i < n; ++i) {
      //   if (s[i] == s[i-1]) {
      //     c1++;
      //   } else {
      //     break;
      //   }
      // }
      // int j;
      // for (j = n-2; j >= 0; --j) {
      //   if (s[j] == s[j+1]) {
      //     c2++;
      //   } else {
      //     break;
      //   }
      // }
      // if (c1 <= c2) {
      //   for (int i2 = i-1; i2 >= 0; --i2) {
      //     s[i2] = s[i];
      //   }
      // } else {
      //   for (int i2 = j+1; i2 < n; ++i2) {
      //     s[i2] = s[j];
      //   }
      // }
      if (s[0] == 'b') s[0] = 'a';
      else s[0] = 'b';
      cout<<s<<endl;
    }
  }
  return 0;
}
