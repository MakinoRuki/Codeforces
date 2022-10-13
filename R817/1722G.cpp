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
int ans[N];
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    if (n % 2 == 0) {
      int n2 = n/2;
      if (n2%2==0) {
        for (int i = 0; i < n; ++i) {
          ans[i] = i;
        }
      } else {
        for (int i = 0; i < n; ++i) {
          ans[i] = i;
        }
        ans[0] = (1<<30)+1;
        ans[2] += (1<<30);
      }
    } else {
      int n2 = (n-1)/2;
      if (n2 % 2 == 0) {
        for (int i = 0; i < n-1; ++i) {
          ans[i] = i;
        }
        ans[n-1] = (1<<30);
        ans[1] += (1<<30);
      } else {
        for (int i = 0; i < n-1; ++i) {
          ans[i] = i;
        }
        ans[n-1] = (1<<30);
        ans[0] += (1<<30) + 1;
      }
    }
    for (int i = 0; i < n; ++i) {
      printf("%d", ans[i]);
      if (i < n-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
