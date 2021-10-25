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
#define M 12
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
string s;
int a[N];
bool comp(int x) {
  for (int i = 2; i < x; ++i) {
    if (x%i == 0) return true;
  }
  return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int sum=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    if (comp(sum)) {
      printf("%d\n", n);
      for (int i = 1; i <= n; ++i) {
        printf("%d", i);
        if (i < n) cout<<" ";
        else cout<<endl;
      }
    } else {
      int id = 0;
      for (id = 1; id <= n; ++id) {
        if (a[id] % 2) {
          break;
        }
      }
      printf("%d\n", n-1);
      int cnt=0;
      for (int i =1; i <= n; ++i) {
        if (i == id) continue;
        printf("%d", i);
        cnt++;
        if (cnt < n-1) cout<<" ";
        else cout<<endl;
      }
    }
  }
  return 0;
}
