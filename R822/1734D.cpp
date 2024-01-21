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
#define N 500005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    bool ok=false;
    ll sum=a[k],mx=a[k];
    int l = k-1;
    int i;
    ll tmp=0LL;
    for (i = k+1; i <= n; ++i) {
      if (sum + tmp+ a[i] >= 0) {
        sum += a[i];
        mx = max(mx, sum);
      } else {
        if (l < 1) break;
        while(l >= 1 && tmp+a[l]+mx>=0) {
          tmp+=a[l];
          l--;
          if (sum+tmp+a[i]>=0) {
            break;
          }
        }
        if (sum+tmp+a[i]>=0) {
          mx=max(mx, sum+a[i]);
          sum+=a[i];
        } else {
          break;
        }
      }
    }
    if (i > n) ok=true;
    int r=k+1;
    sum=a[k];
    mx=a[k];
    tmp=0LL;
    for (i = k-1; i >= 1; --i) {
      if (sum + tmp+a[i]>=0) {
        sum+=a[i];
        mx=max(mx, sum);
      } else {
        if (r > n) break;
        while(r <= n && tmp+a[r]+mx>=0) {
          tmp += a[r];
          r++;
          if (tmp+sum+a[i]>=0) {
            break;
          }
        }
        if (sum+tmp+a[i]>=0) {
          sum+=a[i];
          mx=max(mx, sum);
        } else {
          break;
        }
      }
    }
    if (i < 1) ok=true;
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
