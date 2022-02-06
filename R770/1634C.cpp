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
#define M 500005
#define N 502
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    if ((n == 1) && (k > 1)) {
      puts("NO");
      continue;
    }
    if ((n*k)%2) {
      if (k > 1) {
        puts("NO");
      } else {
        puts("YES");
        for (int i = 1; i <= n*k; ++i) {
          printf("%d\n", i);
        }
      }
    } else {
      int c1 = 1, c2 = 2;
      int tmp = (n*k)/2;
      if (tmp % k != 0) {
        puts("NO");
        continue;
      }
      puts("YES");
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
          if (i%2) {
            a[i][j]=c1;
            printf("%d", a[i][j]);
            
            c1+=2;
            if (j<k) cout<<" ";
            else cout<<endl;
          } else {
            a[i][j] = c2;
            printf("%d", a[i][j]);
            c2 += 2;
            
            if (j<k) cout<<" ";
            else cout<<endl;
          }
        }
      }
      // cout<<"??"<<endl;
      // for (int i = 1; i <= n; ++i) {
      //   for (int l = 1; l <= k; ++l) {
      //     for (int r = l; r <= k; ++r) {
      //       int sum=0;
      //       for (int j = l; j <= r; ++j) {
      //         sum += a[i][j];
      //       }
      //       if (sum % (r-l+1)) cout<<i<<" "<<l<<" "<<r<<endl;
      //     }
      //   }
      // }
    }
    
  }
  return 0;
}
