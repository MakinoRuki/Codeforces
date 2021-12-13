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
#define N 100002
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
int s, t;
bool pm[10000];
int ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int a,b;
    scanf("%d%d%d", &n, &a, &b);
    if (abs(a-b) > 1 || a + b > n-2) {
      puts("-1");
    } else {
      for (int i = 1; i <= n; ++i) {
        ans[i] = i;
      }
      if (a > b) {
        for (int i = 2; i < n; ++i) {
          if (b == 0) {
            swap(ans[i], ans[i+1]);
            continue;
          }
          if (i % 2 == 0) {
            if (a > 0) {
              swap(ans[i], ans[i+1]);
              a--;
            }
          } else {
            if (b > 0) {
              b--;
            }
          }
        }
      } else if (a < b) {
        for (int i = n-1; i >= 2; --i) {
          if (a == 0) {
            swap(ans[i], ans[i-1]);
            continue;
          }
          if ((n-i) % 2) {
            if (b > 0) {
              swap(ans[i], ans[i-1]);
              b--;
            }
          } else {
            if (a > 0) {
              a--;
            }
          }
        }
      } else {
        for (int i = 2; i < n; ++i) {
          if (i % 2 == 0) {
            if (a > 0) {
              swap(ans[i], ans[i+1]);
              a--;
            }
          } else {
            if (b > 0) {
              b--;
            }
          }
        }
      }
      for (int i = 1; i <= n; ++i) {
        printf("%d", ans[i]);
        if (i < n) cout<<" ";
        else cout<<endl;
      }
    }
  }
  return 0;
}
