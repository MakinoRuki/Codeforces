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
#define N 200005
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int b[N];
int a[N];
int ln[N], rn[N];
int c[N];
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      c[i] = 0;
    }
    c[n+1] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    for (int i = n; i >= 1; --i) {
      if (a[i] <= b[i-1]) {
        c[i] = 1;
      }
    }
    for (int i = n; i >= 1; --i) {
      c[i] += c[i+1];
    }
    
    // int j = 1;
    // for (int i = 1; i <= n; ++i) {
    //   while(j <= n && b[j] < a[i]) {
    //     j++;
    //   }
    //   l[i] = j;
    // }
    // j = n;
    // for (int i = n; i >= 1; --i) {
    //   while(j >= 1 && l[j] > i) {
    //     j--;
    //   }
    //   r[i] = j;
    // }
    for (int i = 1; i <= n; ++i) {
      int l = 1, r = i;
      while(l < r) {
        int mid=(l+r)/2;
        if (b[mid] < a[i]) {
          l = mid+1;
        } else {
          r = mid;
        }
      }
      ln[i] = r;
      l = i, r = n;
      while(l < r) {
        int mid=(l+r+1)/2;
      //  if (i == 1) cout<<l<<" "<<r<<" "<<mid<<endl;
        if (c[i+1] - c[mid+1] == mid-i) {
          l = mid;
        } else {
          r = mid-1;
        }
      }
      rn[i] = r;
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d", b[ln[i]]-a[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d", b[rn[i]]-a[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
