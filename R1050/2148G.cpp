
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
#define M 5002
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
int cnt[N];
int getgcd(int x, int y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i =1 ; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[i]=0;
    }
    int g = a[1];
    for (int j = 2; j * j <= a[1]; ++j) {
      if ((a[1] % j) == 0) {
        cnt[j]++;
        if (a[1] / j != j) cnt[a[1]/j]++;
      }
    }
    cnt[a[1]]++;
    printf("%d", 0);
    int mx=0;
    for (int i = 2; i <= n; ++i) {
      int g2 = getgcd(g, a[i]);
      int res=0;
      for (int j = 2; j * j <= a[i]; ++j) {
        if ((a[i] % j)==0) {
          cnt[j]++;
          if (((j%g2) == 0)) {
            if (j/g2>1) mx = max(mx, cnt[j]);
            //if (i == 4 && j == 2) cout<<"j/g2="<<j/g2<<" "<<cnt[j]<<endl;
          }
          if (a[i]/j != j) {
            int x=a[i]/j;
            cnt[x]++;
            if (((x%g2)==0)) {
              if (x/g2>1) mx=max(mx, cnt[x]);
            }
          }
        }
      }
      cnt[a[i]]++;
      if (a[i]/g2>1) {
        mx=max(mx, cnt[a[i]]);
      }
      if (g2 < g) {
        mx=max(mx, cnt[g]);
        printf(" %d", i-1);
      } else {
        printf(" %d", mx);
      }
      g = g2;
     // cout<<"i="<<i<<" "<<cnt[2]<<" "<<cnt[3]<<" "<<cnt[4]<<" "<<cnt[6]<<" "<<mx<<endl;
    }
    cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
