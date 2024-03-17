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
#include <list>
#define N 300005
#define M 1005
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
    scanf("%d%d", &n, &m);
    int r = m%n;
    if (m < n) {
      puts("No");
      continue;
    }
    if (r == 0) {
      puts("Yes");
      for (int i = 1; i <= n; ++i) {
        printf("%d ", m/n);
      }
      cout<<endl;
    } else {
      if (n%2) {
        puts("Yes");
        for (int i = 1; i <= n; ++i) {
          if (i == 1) printf("%d ", m/n+r);
          else printf("%d ", m/n);
        }
        cout<<endl;
      } else {
        if (r%2) puts("No");
        else {
          puts("Yes");
          for (int i = 1; i <= n; ++i) {
            if (i <= 2) printf("%d ", m/n+r/2);
            else printf("%d ", m/n);
          }
          cout<<endl;
        }
      }
    }
  }
  return 0;
}
