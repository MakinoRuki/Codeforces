
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
#define N 500005
#define M 50
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
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    int res=0;
    for (int i = 30; i >=0; --i) {
      int c1=0,c0=0;
      int bt=0;
      for (int j = 1; j <= n; ++j) {
        int x = ((1<<i)&a[j])>0;
        int y = ((1<<i)&b[j])>0;
        if (x != y) {
          if (j%2) {
            if (bt==0) bt = 1;
            else bt=0;
          } else{
            if (bt==0) bt=-1;
            else bt=0;
          }
        }
      }
      if (bt!=0) {
        res=bt;
        break;
      }
    }

    // for (int j = n; j >= 1; --j) {
      //   int x = ((1<<i)&a[j])>0;
      //   int y = ((1<<i)&b[j])>0;
      //   if (x!=y) {
      //     if (j%2) {
      //       if (bt==0 || bt==1) {
      //         c1++;
      //         bt=1;
      //       } else {
      //         break;
      //       }
      //     } else {
      //       if (bt==0 || bt == -1) {
      //         c0++;
      //         bt=-1;
      //       } else {
      //         break;
      //       }
      //     }
      //   }
      // }
     // if (i<=4) cout<<"i="<<i<<" "<<c1<<" "<<c0<<endl;
      // if (c1 > c0) {
      //   int dt=c1-c0;
      //   if (dt%2) {res=1; break;}
      // } else if (c0 > c1) {
      //   int dt=c0-c1;
      //   if (dt%2) {res=-1; break;}
      // }
    if (res>0) puts("Ajisai");
    else if (res<0) puts("Mai");
    else puts("Tie");
  }
  // cin>>n;
  // srand((unsigned)time(0));
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
