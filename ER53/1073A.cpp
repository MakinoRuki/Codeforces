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
#define N 1002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, t;
string s;
int sum[27][N];
int main() {
  cin>>n>>s;
  memset(sum, 0, sizeof(sum));
  for (int i = 0; i < 26; ++i) {
    for (int j = 1; j <= n; ++j) {
      sum[i][j] = sum[i][j-1] + (s[j-1] == 'a'+i);
    }
  }
  int i2=-1,j2=-1;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      int k;
      for (k = 0; k < 26; ++k) {
        if ((sum[k][j]-sum[k][i-1])*2>(j-i+1)) {
          break;
        }
      }
      if (k < 26) {
        continue;
      }
      i2 = i-1;
      j2 = j-1;
      break;
    }
    if (i2 >= 0) break;
  }
  if (i2>=0) {
    cout<<"YES"<<endl;
    cout<<s.substr(i2, j2-i2+1)<<endl;
  } else {
    cout<<"NO"<<endl;
  }
  return 0;
}
