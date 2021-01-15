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
#define M 2000005
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
int t;
int w,h;
int a[N], b[N];
ll dp[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int on=0, en=0;
    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      if (x%2==0) a[++en] = x;
      else b[++on] = x;
    }
    sort(a+1, a+en+1);
    sort(b+1, b+on+1);
    int i = en, j = on;
    ll as = 0, bs = 0;
    while(i >= 1 || j >= 1) {
      if (j < 1 || (i >= 1 && a[i] > b[j])) {
        as += a[i];
        i--;
      } else {
        j--;
      }
      if (i < 1 || (j >= 1 && b[j] > a[i])) {
        bs += b[j];
        j--;
      } else {
        i--;
      }
   //   cout<<i<<" "<<j<<" "<<as<<" "<<bs<<endl;
    }
    if (as > bs) {
      cout<<"Alice"<<endl;
    } else if (as < bs) {
      cout<<"Bob"<<endl;
    } else {
      cout<<"Tie"<<endl;
    }
  }
  return 0;
}
