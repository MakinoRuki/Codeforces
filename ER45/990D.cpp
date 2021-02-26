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
#define M 21
#define N 1005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,a,b;
bool mat[N][N];
// int par[N];
// int find(int x) {
//   return x == par[x] ? x : par[x] = find(par[x]);
// }
// int getres() {
//   for (int i =1; i<=n; ++i) {
//     par[i] = i;
//   }
//   for (int i = 1; i <= n; ++i) {
//     for (int j = i + 1; j <= n; ++j) {
//       if (mat[i][j]) {
//         int pi = find(i);
//         int pj = find(j);
//         if (pi != pj) {
//           par[pi] = pj;
//         }
//       }
//     }
//   }
//   int cnt=0;
//   for (int i =1; i <= n; ++i) {
//     par[i] = find(i);
//     if (par[i] == i) cnt++;
//   }
//   return cnt;
// }
int main() {
  cin>>n>>a>>b;
  memset(mat, false, sizeof(mat));
  if (a > 1 && b > 1) {
    puts("NO");
  } else {
    if (a == 1 && b == 1) {
      if (n == 1) {
        puts("YES");
        cout<<"0"<<endl;
      } else if (n == 2 || n==3) {
        puts("NO");
      } else {
        puts("YES");
        for (int i = 1; i < n; ++i) {
          mat[i][i+1] = mat[i+1][i] = true;
        }
        for (int i = 1; i <= n; ++i) {
          for (int j = 1; j <= n; ++j) {
            if (mat[i][j]) cout<<1;
            else cout<<0;
          }
          cout<<endl;
        }
      }
    } else if (a > 1) {
      if (n == 1) {
        puts("NO");
        return 0;
      }
      puts("YES");
      for (int i = a; i < n; ++i) {
        mat[i][i+1] = true;
        mat[i+1][i] = true;
      }
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          if (mat[i][j]) cout<<1;
          else cout<<0;
        }
        cout<<endl;
      }
    } else {
      puts("YES");
      for (int i = b; i < n; ++i) {
        mat[i][i+1] = true;
        mat[i+1][i] = true;
      }
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          if (i ==j || mat[i][j]) cout<<0;
          else cout<<1;
        }
        cout<<endl;
      }
    }
  }
  // cin>>n;
  // memset(mat, false, sizeof(mat));
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = i + 1; j <= n; ++j) {
  //     int r = rand()%2;
  //     if (r) mat[i][j] = mat[j][i] = true;
  //   }
  // }
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     cout<<mat[i][j];
  //   }
  //   cout<<endl;
  // }
  // int n1 = getres();
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = i + 1; j <= n; ++j) {
  //     mat[i][j] = mat[j][i] = !mat[i][j];
  //   }
  // }
  // int n2=getres();
  // cout<<n1<<" "<<n2<<endl;
  return 0;
}
