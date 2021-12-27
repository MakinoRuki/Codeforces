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
#define N 400005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
int a[N];
string sa, sb;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    cin>>sa;
    cin>>sb;
    int n01=0,n10=0,n00=0,n11=0;
    for (int i = 0; i < n; ++i) {
      if (sa[i] == '0' && sb[i] == '1') n01++;
      else if (sa[i] == '0' && sb[i] == '0') n00++;
      else if (sa[i] == '1' && sb[i] == '1') n11++;
      else n10++;
    }
    int ans = -1;
    if (n10 == n01) {
      ans = n01+n10;
    }
    for (int i = 0; i < n; ++i) {
      if (sa[i] == '1') {
        int m01=n01,m00=n00,m10=n10,m11=n11;
        if (sb[i] == '0') m10--;
        else m11--;
        int x01=m11, x10=m00, x00=m10, x11=m01;
        if (sb[i] == '0') x10++;
        else x11++;
        if (x01 == x10) {
          ans = (ans < 0 ? x10+x01+1 : min(ans, x10+x01+1));
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
