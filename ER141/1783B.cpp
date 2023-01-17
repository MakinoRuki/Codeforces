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
#define N 100
#define M 80
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, q;
int k;
int t;
int a[N][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int l =1,r=n*n;
    bool f = true;
    for (int i = 1; i <= n; ++i) {
      if (i % 2) {
        for (int j = 1; j <= n; ++j) {
          if (f) {
            a[i][j] = l;
            l++;
          } else {
            a[i][j] = r;
            r--;
          }
          f=!f;
        }
      } else {
        for (int j = n; j >= 1; --j) {
          if (f) {
            a[i][j] = l++;
          } else {
            a[i][j]=r--;
          }
          f =!f;
        }
      }
    }
    for (int i  = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        printf("%d", a[i][j]);
        if (j<n) cout<<" ";
        else cout<<endl;
      }
    }
  }
  return 0;
}
