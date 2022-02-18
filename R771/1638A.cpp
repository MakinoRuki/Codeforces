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
#define M 202
#define N 600
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int p[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);
    }
    int i;
    for (i = 1; i <= n; ++i) {
      if (p[i] != i) {
        break;
      }
    }
    if (i <= n) {
      int j;
      for (j = i+1; j <= n; ++j) {
        if (p[j] == i) {
          break;
        }
      }
      int l = i, r = j;
      while(l < r) {
        swap(p[l], p[r]);
        l++;
        r--;
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d", p[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
