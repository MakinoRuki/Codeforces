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
ll a[N];
ll sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    sum[0]=0LL;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    if (sum[n]%2) {
        puts("-1");
        continue;
    }
    int i;
    for (i = 1; i < n; ++i) {
        if (sum[i] >= sum[n]-sum[i]) {
            break;
        }
    }
    if (i < n && (sum[i] == sum[n]-sum[i])) {
       puts("1");
       for (int i = 1; i <= n; ++i) {
           printf("%lld ", a[i]);
       }
       cout<<endl;
    } else {
        if (n == 2) puts("-1");
        else {
          if (2*a[i] > sum[n]) {
              puts("-1");
              continue;
          }
          puts("2");
          ll dt = (sum[n]-sum[i-1]-sum[i-1])/2LL;
          for (int j = 1; j <= n; ++j) {
              if (j < i) {
                  printf("%lld ", a[j]);
                  a[j]=0;
              } else {
                  if (j == i) {
                      printf("%lld ", a[j]-dt);
                      a[j]=dt;
                  } else {
                      ll dt2=min(a[j], dt);
                      printf("%lld ", a[j]-dt2);
                      a[j] = dt2;
                      dt -= dt2;
                  }
              }
          }
          cout<<endl;
          for (int i =1 ; i <= n; ++i) {
              printf("%lld ", a[i]);
          }
          cout<<endl;
        }
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
