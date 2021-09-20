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
#define M 12
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
string s1, s2;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    cin>>s1>>s2;
    int ans = 0;
    int i = 0;
    while(i < n) {
      if (s1[i] == '0' && s2[i] == '0') {
        if (i + 1 < n && s1[i + 1] == '1' && s2[i+1] == '1') {
          ans += 2;
          i += 2;
        } else {
          ans++;
          i++;
        }
      } else if (s1[i] == '1' && s2[i] == '1') {
        if (i + 1 < n && s1[i+1] == '0' &&s2[i+1] == '0') {
          ans+=2;
          i += 2;
        } else {
          i++;
        }
      } else {
        ans += 2;
        i++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
