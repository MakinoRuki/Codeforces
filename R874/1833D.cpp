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
#define N 2005
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int ans[N];
int ans2[N];
void getans(int l1, int r1, int l2, int r2, int l3, int r3) {
  int id = 1;
  for (int i = l1; i <= r1; ++i) {
    ans[id++] = a[i];
  }
  for (int i = r2; i >= l2; --i) {
    ans[id++] = a[i];
  }
  for (int i = l3; i <= r3; ++i) {
    ans[id++] = a[i];
  }
}
void getans2() {
  int id=1;
  ans[id++] = a[n];
  if (a[1] > a[n-1]) {
    for (int i =1 ; i < n; ++i) {
      ans[id++] = a[i];
    }
  } else {
    for (int i = n-1; i >= 1; --i) {
      ans[id++] = a[i];
    }
  }
  int l = 1, r = n-1;
  while(l < r) {
    if (r-1>=1 && a[r-1] > a[l]) {
      r--;
    } else {
      break;
    }
  }
  ans2[1] = a[n];
  id = 2;
  for (int i = n-1; i >= r; --i) {
    ans2[id++] = a[i];
  }
  for (int i = 1; i < r; ++i) {
    ans2[id++] = a[i];
  }
  int i;
  for (i = 1; i <= n; ++i) {
    if (ans2[i] != ans[i]) {
      break;
    }
  }
  if (i < n && ans2[i] > ans[i]) {
    for (int i = 1; i <= n; ++i) {
      ans[i] = ans2[i];
    }
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    if (n == 1) {
      puts("1");
      continue;
    }
    int idx1 = 0, idx2 = 0;
    for (int i = 1;  i<= n; ++i) {
      if (a[i] == n) idx1 = i;
      if (a[i] == n-1) idx2=i;
    }
    if (idx1 == 1) {
      if (idx2 < n) {
        int l = 1, r = idx2-1;
        while(l < r) {
          if (r-1>=1 && a[l] < a[r-1]) {
            r--;
          } else {
            break;
          }
        }
        getans(idx2, n, r, idx2-1, 1, r);
      } else {
        getans2();
      }
    } else {
      if (idx1 < n) {
        int l = 1, r = idx1-1;
        while(l < r) {
          if (r-1>=1 && a[l] < a[r-1]) {
            r--;
          } else {
             break;
          }
        }
        getans(idx1, n, r, idx1-1, 1, r);
      } else {
        getans2();
      }
    }
    for (int i =1; i <= n; ++i) {
      printf("%d", ans[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
