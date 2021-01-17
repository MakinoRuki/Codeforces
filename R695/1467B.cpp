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
#define N 300002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, t;
int a[N];
int hv[N];
bool check(int i) {
  if (i-1>=1 && i+1<=n) {
    if (a[i] > a[i-1] && a[i]>a[i+1]) return true;
    if (a[i]<a[i-1] && a[i]<a[i+1]) return true;
    return false;
  }
  return false;
}
int getres(int i) {
  int cnt=0;
  if (check(i)) cnt++;
  if (check(i-1)) cnt++;
  if (check(i+1)) cnt++;
  return cnt;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i=1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int tot=0;
    for (int i = 1; i <= n; ++i) {
      hv[i] = 0;
    }
    for (int i = 2; i < n; ++i) {
      if (a[i] > a[i-1] && a[i] > a[i+1]) {
        hv[i] = 1;
        tot++;
      } else if (a[i] < a[i-1] && a[i] < a[i+1]) {
        hv[i] = -1;
        tot++;
      } else {
        hv[i] = 0;
      }
    }
    int ans=tot;
    for (int i = 1; i <= n; ++i) {
      int n1=0;
      if (hv[i] != 0) n1++;
      if (i-1>=1 && hv[i-1] != 0) n1++;
      if (i+1<=n && hv[i+1] != 0) n1++;
      int n2=0;
      int tmp=a[i];
      a[i] = 2*inf;
      n2 = getres(i);
      if (n2 < n1) {
        ans=min(ans, tot-n1+n2);
      }
      a[i] = -inf;
      n2 = getres(i);
      if (n2 < n1) {
        ans=min(ans, tot-n1+n2);
      }
      if (i-1>=1) {
        a[i] = a[i-1];
        n2 = getres(i);
        if (n2<n1) {
          ans=min(ans, tot-n1+n2);
        }
      }
      if (i+1<=n) {
        a[i] = a[i+1];
        n2 = getres(i);
        if (n2<n1) {
          ans=min(ans, tot-n1+n2);
        }
      }
      a[i] = tmp;
    }
    // for (int i= 1; i <= n; ++i) {
    //   if (i == 1) {
    //     if (i+1<=n && hv[i+1] != 0) {
    //       ans =min(ans, tot-1);
    //     }
    //   } else if (i == n) {
    //     if (i-1>=1 && hv[i-1] != 0) {
    //       ans = min(ans, tot-1);
    //     }
    //   } else {
    //     if (i+1<=n && i-1>=1) {
    //       if (hv[i] != 0) {
    //         if (hv[i-1] !=0 && hv[i+1] != 0) {
    //           if (hv[i-1] == hv[i+1]) {
    //             ans=min(ans, tot-3);
    //           }
    //         } else if (hv[i-1] != 0 || hv[i+1] != 0) {
    //           ans=min(ans, tot-2);
    //         } else {
    //           ans=min(ans, tot-1);
    //         }
    //       } else {
    //         if (hv[i-1] != 0 && hv[i+1] != 0) {
    //           ans=min(ans, tot-1);
    //         }
    //         // else if (hv[i-1] != 0 || hv[i+1] != 0) {
    //         //   ans=min(ans, tot-1);
    //         // }
    //       }
    //     } else if (i+1<=n && hv[i+1] != 0) {
    //       ans=min(ans, tot-1);
    //     } else if (i-1>=1 && hv[i-1] != 0) {
    //       ans=min(ans, tot-1);
    //     }
    //   }
    // }
    printf("%d\n", ans);
  }
  return 0;
}
