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
#define N 8000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int t, k;
string s;
bool pm[N];
int main() {
  memset(pm, true, sizeof(pm));
  for (int i = 2; i < N; ++i) {
    if (pm[i]) {
      for (int j = i*i; j < N; j += i) {
        pm[j] = false;
      }
    }
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    cin>>s;
    int x = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9') {
        x = s[i]-'0';
        break;
      }
    }
    if (x > 0) {
      puts("1");
      printf("%d\n", x);
    } else {
      vector<int> ds = {2,3,5,7};
      vector<int> cnt = {0,0,0,0};
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
          if (s[i]-'0' == ds[j]) {
            cnt[j]++;
          }
        }
      }
      int j;
      for (j = 0; j < 4; ++j) {
        if (cnt[j] >= 2) break;
      }
      if (j < 4) {
        puts("2");
        printf("%d\n", ds[j]*10+ds[j]);
      } else {
        int len = n;
        int res = 0;
        for (int j = 1; j < (1<<n); ++j) {
          int res2=0;
          int l1=0;
          for (int i = 0; i < n; ++i) {
            if ((1<<i)&j) {
              res2 = res2 * 10 + s[i]-'0';
              l1++;
            }
          }
          if (!pm[res2]) {
            if (l1 <= len) {
              len=l1;
              res = res2;
            }
          }
        }
        printf("%d\n%d\n", len, res);
      }
    }
  }
 return 0;
}
