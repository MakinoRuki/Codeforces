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
#include <random>
#include <ctime>
#define M 202
#define N 200
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int m, k, q;
int n;
int t;
int c;
int main() {
  cin>>t;
  for (int cas=1;cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    int ans = 0;
    int pre = -1;
    int cnt=0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        if (pre >= 0 && i - pre < 3) {
          int det = i - pre;
          ans += 3 - det;
        }
        pre=  i;
        cnt++;
      }
    }
    if (cnt == 0) {
      puts("0");
    } else if (cnt == 1) {
      puts("0");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}
