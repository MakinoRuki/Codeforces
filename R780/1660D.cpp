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
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int m, k, q;
int n;
int t;
int c;
int a[N];
string s;
int main() {
  cin>>t;
  for (int cas=1;cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int ans = 0;
    int l = n, r= 0;
    int bg = 1;
    while(bg <= n && a[bg] == 0) {
      bg++;
    }
    if (bg > n) {
      printf("%d %d\n", l, r);
    } else {
      a[n+1] = 0;
      for (int i = bg + 1; i <= n+1; ++i) {
        if (a[i] == 0) {
          if (bg > 0) {
            int ed = i-1;
            int cnt=0;
            int n2 = 0;
            for (int j = bg; j <= ed; ++j) {
              if (a[j] < 0) cnt++;
              if (abs(a[j]) == 2) n2++;
            }
            if (cnt % 2 == 0) {
              if (n2 > ans) {
                ans = n2;
                l = bg-1;
                r = n-ed;
              }
            } else {
              int id1=-1, id2=-1;
              for (int j = bg; j <= ed; ++j) {
                if (a[j] < 0) {
                  id1 = j;
                  break;
                }
              }
              for (int j = ed; j >= bg; --j) {
                if (a[j] < 0) {
                  id2 = j;
                  break;
                }
              }
              cnt = 0, n2 = 0;
              for (int j = id1+1; j <= ed; ++j) {
                if (abs(a[j]) == 2) n2++;
              }
              if (n2 > ans) {
                ans = n2;
                l = id1;
                r = n-ed;
              }
              cnt = 0, n2 = 0;
              for (int j = id2-1; j >= bg; --j) {
                if (abs(a[j]) == 2) n2++;
              }
              if (n2 > ans) {
                ans = n2;
                l = bg - 1;
                r = n - id2 + 1;
              }
            }
            bg = 0;
          }
        } else {
          if (bg == 0) bg = i;
        }
      }
      if (bg > 0) {

      }
      printf("%d %d\n", l, r);
    }
  }
  return 0;
}
