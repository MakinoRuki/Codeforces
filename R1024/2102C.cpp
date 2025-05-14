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
#include <stack>
#include <bitset>
#include <chrono>
#define N 200005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, p, q;
int k;
int t;
int a[N];
int ans[M][M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int r = (n+1)/2;
    int c = (n+1)/2;
    int cnt=0;
    ans[r][c] = cnt;
    int dt=2;
    int tot=1;
    while(true) {
        if (n&1) {
            r--;
            for (int i = 1; i <= dt; ++i) {
                if (tot+1>n*n) break;
                ans[r][c]=++cnt;
                tot++;
                c++;
            }
            c--;
            for (int i = 1; i <= dt; ++i) {
                r++;
                if (tot+1>n*n) break;
                 tot++;
                ans[r][c]=++cnt;
            }
            for (int i = 1; i <= dt; ++i) {
                c--;
                if (tot+1>n*n) break;
                 tot++;
                ans[r][c]=++cnt;
            }
            for (int i = 1; i <= dt; ++i) {
                r--;
                if (tot+1>n*n) break;
                 tot++;
                ans[r][c]=++cnt;
            }
            dt += 2;
        } else {
            c++;
            for (int i = 1; i <= dt; ++i) {
                if (tot+1>n*n) break;
                 tot++;
                ans[r][c]=++cnt;
                r++;
            }
            r--;
            for (int i = 1; i <= dt; ++i) {
                c--;
                if (tot+1>n*n) break;
                 tot++;
                ans[r][c]=++cnt;
            }
            for (int i = 1; i <= dt; ++i) {
                r--;
                if (tot+1>n*n) break;
                 tot++;
                ans[r][c]=++cnt;
            }
            for (int i = 1; i <= dt; ++i) {
                c++;
                if (tot+1>n*n) break;
                 tot++;
                ans[r][c]=++cnt;
            }
            dt += 2;
        }
        if (tot+1>n*n) break;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", ans[i][j]);
        }
        cout<<endl;
    }
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
