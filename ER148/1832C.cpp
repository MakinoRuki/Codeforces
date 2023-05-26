#include <iostream>
#include <cstdio>
#include <stdio.h>
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
#include <cstring>
#define N 300005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
int a[N];
bool mk[N];
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    //ll n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      mk[i] = true;
    }
    int ans=0;
    int tp = -1;
    int pre = 1;
    for (int i = 2; i <= n; ++i) {
      if (a[i] > a[pre]) {
        if (tp == 1) {
          mk[pre] = false;
         // cout<<"i1="<<pre<<endl;
          pre=i;
        } else if (tp == 0) {
          tp = 1;
          pre=i;
        } else {
          tp = 1;
          pre= i;
        }
      } else if (a[i] < a[pre]) {
        if (tp == 0) {
          mk[pre] = false;
        //  cout<<"i2="<<pre<<endl;
          pre=i;
        } else if (tp == 1) {
          pre=i;
          tp=0;
        } else {
          tp=0;
          pre=i;
        }
      } else {
        mk[i]=false;
       // cout<<"i3="<<i<<endl;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (mk[i]) ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
