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
#define N 600005
#define M 1002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int rmx[N], cmx[N];
int rn[N], cn[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    int mx=0;
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x;
            scanf("%d", &x);
            a[(i-1)*m+j] = x;
            if (x > mx) {
                mx = x;
                cnt=1;
            } else if (x == mx) {
                cnt++;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
      rmx[i]=0,rn[i]=0;
      for (int j = 1; j <= m; ++j) {
          int x=a[(i-1)*m+j];
          if (x>rmx[i]) {
              rmx[i]=x;
              rn[i]=1;
          } else if (x == rmx[i]) {
              rn[i]++;
          }
      }
    }
    for (int j = 1; j <= m; ++j) {
      cmx[j]=0,cn[j]=0;
      for (int i = 1; i <= n; ++i) {
          int x=a[(i-1)*m+j];
          if (x>cmx[j]) {
              cmx[j]=x;
              cn[j]=1;
          } else if (x == cmx[j]) {
              cn[j]++;
          }
      }
    }
    int ans=mx;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x=max(rmx[i], cmx[j]);
            int y=0;
            if (rmx[i] == x) {
                y += rn[i];
            }
            if (cmx[j] == x) {
                y += cn[j];
            }
            if (a[(i-1)*m+j] == x) {
                y--;
            }
            if (x == mx) {
                if (y == cnt) {
                    ans=min(ans, x-1);
                }
            }
        }
    }
    printf("%d\n", ans);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
